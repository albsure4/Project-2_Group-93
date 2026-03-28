//
// Created by ticol on 3/25/2026.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "DataEntries.h"
#include "QuickSort.h"
#include "HeapSort.h"

void handleInternalCommas(std::stringstream& stream, std::string& parsed, std::string garbage) {
    while(parsed[0] == '"' and parsed.back() != '"'){
        getline(stream, garbage, ',');
        parsed.append(',' + garbage);
    }
}

int main(){

/*

while (getline(readFile, text)){
    std::cout << text;
}
*/

std::cout << "Welcome to our Project!\n\n";
std::cout << "* In order to make a selection, please type the number corresponding to it *\n\n";
std::cout << "Please select a country:\n";
std::cout << "1. United States\n2. Brazil\n3. Canada\n4. Germany\n5. France\n6. United Kingdom\n7. India\n8. Japan\n9. South Korea\n10. Mexico\n11. Russia\n\n";

std::string country;
std::cin >> country;
std::string text;

std::string fileName;

//
if (country == "1") {
    fileName = "Data/US_Trending.csv";
}
else if (country == "2") {
    fileName = "Data/BR_Trending.csv";
}
else if (country == "3") {
    fileName = "Data/CA_Trending.csv";
}
else if (country == "4") {
    std::cout << "hello";
    fileName = "Data/DE_Trending.csv";
}
else if (country == "5") {
    fileName = "Data/FR_Trending.csv";
}
else if (country == "6") {
    fileName = "Data/GB_Trending.csv";
}
else if (country == "7") {
    fileName = "Data/IN_Trending.csv";
}
else if (country == "8") {
    fileName = "Data/JP_Trending.csv";
}
else if (country == "9") {
    fileName = "Data/KR_Trending.csv";
}
else if (country == "10") {
    fileName = "Data/MX_Trending.csv";
}
else if (country == "11") {
    fileName = "Data/RU_Trending.csv";
}
else {
    std::cerr << "Incorrect Input- Must be a number 1-11\n\n";
}

std::ifstream readFile(fileName);

if (!readFile.is_open()) {
    std::cerr << "Could not open file!" << std::endl; //error message if data set is not accessed
}

std::vector<dataEntries> listOfVideos; //create vector of class objects where an object is a singular trending video
getline(readFile, text); //ignore the first line which has the column titles
while (getline(readFile, text)){
    std::stringstream stream(text);
    std::string title;
    std::string views;
    std::string likes;
    std::string comments;
    std::string category;
    std::string channel;
    std::string garbage; //store video data we don't need here to keep parsing
    for (int i = 0; i < 13; i++) {
        if (i == 2) {
            getline(stream, title, ',');
            handleInternalCommas(stream, title, garbage);
        }
        else if (i == 3) {
            getline(stream, channel, ',');
            handleInternalCommas(stream, channel, garbage);
        }
        else if (i == 4) {
            getline(stream, views, ',');
        }
        else if (i == 5) {
            getline(stream, likes, ',');
        }
        else if (i == 8) {
            getline(stream, category, ',');
        }
        else if (i == 10) {
            getline(stream, comments, ',');
        }
        else {
            getline(stream, garbage, ',');
            handleInternalCommas(stream, garbage, garbage);
        }
    }
/*std::cout << title << std::endl;
    std::cout << views << std::endl;
    std::cout << likes << std::endl;
    std::cout << comments << std::endl;
    std::cout << category << std::endl;
    std::cout << channel << std::endl << std::endl;
    std::cout << stream.str() << std::endl;*/
    dataEntries trendingVideo(title, stoi(views), stoi(likes), stoi(comments), stoi(category), channel);
    listOfVideos.push_back(trendingVideo);
}

std::cout << "Select a sorting algorithm\n\n";
std::cout << "1. HeapSort\n";
std::cout << "2. QuickSort\n";

//Take in User input for sorting algorithm type
std::string algo;
std::cin >> algo;

std::cout << "Select an option to sort by\n\n";
std::cout << "1. View Count\n";
std::cout << "2. Like Count\n";
std::cout << "3. Comment Count\n";

//Take in User input for what they want to sort by
std::string sortByType;
std::cin >> sortByType;

std::cout << "Select how you would like to display the top 10\n\n";
std::cout << "1. Channel Name\n";
std::cout << "2. Category\n";
std::cout << "3. Video Name\n";

//Take in User input for what they want to sort by
std::string displayType;
std::cin >> displayType;
if (stoi(algo) == 2) {
    int n = listOfVideos.size();
    if (stoi(sortByType) == 1) {
        quickSort("views", listOfVideos, 0, n - 1);
        for (int i = 0; i < 10; i++) {
            std::cout << i + 1 << ". " << listOfVideos[i].channel << std::endl;
        }
    }
}
else if (stoi(algo) == 1) {
    //int n = listOfVideos.size();
    if (stoi(sortByType) == 1){
        heapSort("views", listOfVideos);
        for (int i = 0; i < 10; i++) {
            std::cout << i + 1 << ". " << listOfVideos[i].channel << std::endl;
        }
    }
    else if (stoi(sortByType) == 2) {
        heapSort("likes", listOfVideos);
        for (int i = 0; i < 10; i++) {
            std::cout << i + 1 << ". " << listOfVideos[i].channel << std::endl;
        }
    }
}
readFile.close();
return 0;
}