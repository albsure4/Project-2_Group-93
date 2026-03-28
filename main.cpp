//
// Created by ticol on 3/25/2026.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>

#include "DataEntries.h"
#include "QuickSort.h"
#include "HeapSort.h"

void handleInternalCommas(std::stringstream& stream, std::string& parsed, std::string garbage) {
    while(parsed[0] == '"' and parsed.back() != '"'){
        getline(stream, garbage, ',');
        parsed.append(',' + garbage);
    }
}

void readFromFile(std::string fileName, std::vector<dataEntries>& videos) {
    std::string text;
    std::ifstream inFile(fileName);
    if (!inFile.is_open()) {
        std::cerr << "Could not open file!" << std::endl; //error message if data set is not accessed
        return;
    }

    getline(inFile, text); //ignore the first line which has the column titles
    while (getline(inFile, text)){
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
        videos.push_back(trendingVideo);
    }
    inFile.close();
}

int main(){

/*

while (getline(readFile, text)){
    std::cout << text;
}
*/
std::vector<dataEntries> listOfVideos; //create vector of class objects where an object is a singular trending video

std::cout << "Welcome to our Project!\n\n";
std::cout << "* In order to make a selection, please type the number corresponding to it *\n\n";
std::cout << "Please select a country:\n";
std::cout << "1. United States\n2. Brazil\n3. Canada\n4. Germany\n5. France\n6. United Kingdom\n7. India\n8. Japan\n9. South Korea\n10. Mexico\n11. Russia\n12. All\n\n";

std::string country;
while (true){ // make sure number is between 1-11, else: retake input
    std::cin >> country;
    if (stoi(country) > 12 || stoi(country) < 1){
        std::cerr << "Incorrect Input- Must be a number 1-11\n";
        continue;
    }
    break;
}

std::string fileName;

if (country == "1") {
    readFromFile("Data/US_Trending.csv", listOfVideos);
}
else if (country == "2") {
    readFromFile("Data/BR_Trending.csv", listOfVideos);
}
else if (country == "3") {
    readFromFile("Data/CA_Trending.csv", listOfVideos);
}
else if (country == "4") {
    std::cout << "hello";
    readFromFile("Data/DE_Trending.csv", listOfVideos);
}
else if (country == "5") {
    readFromFile("Data/FR_Trending.csv", listOfVideos);
}
else if (country == "6") {
    readFromFile("Data/GB_Trending.csv", listOfVideos);
}
else if (country == "7") {
    readFromFile("Data/IN_Trending.csv", listOfVideos);
}
else if (country == "8") {
    readFromFile("Data/JP_Trending.csv", listOfVideos);
}
else if (country == "9") {
    readFromFile("Data/KR_Trending.csv", listOfVideos);
}
else if (country == "10") {
    readFromFile("Data/MX_Trending.csv", listOfVideos);
}
else if (country == "11") {
    readFromFile("Data/RU_Trending.csv", listOfVideos);
}
else if (country == "12"){
    readFromFile("Data/US_Trending.csv", listOfVideos);
    readFromFile("Data/BR_Trending.csv", listOfVideos);
    readFromFile("Data/CA_Trending.csv", listOfVideos);
    readFromFile("Data/DE_Trending.csv", listOfVideos);
    readFromFile("Data/FR_Trending.csv", listOfVideos);
    readFromFile("Data/GB_Trending.csv", listOfVideos);
    //readFromFile("Data/IN_Trending.csv", listOfVideos);
    readFromFile("Data/JP_Trending.csv", listOfVideos);
    readFromFile("Data/KR_Trending.csv", listOfVideos);
    readFromFile("Data/MX_Trending.csv", listOfVideos);
    readFromFile("Data/RU_Trending.csv", listOfVideos);
}

std::ifstream readFile(fileName);

if (listOfVideos.empty())
    return 0;

/*getline(readFile, text); //ignore the first line which has the column titles
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
        std::cout << stream.str() << std::endl;#1#
    dataEntries trendingVideo(title, stoi(views), stoi(likes), stoi(comments), stoi(category), channel);
    listOfVideos.push_back(trendingVideo);
}*/

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
    auto start = std::chrono::high_resolution_clock::now(); // retrieved clock function from https://www.geeksforgeeks.org/cpp/measure-execution-time-function-cpp/
    if (stoi(sortByType) == 1)
        quickSort("views", listOfVideos, 0, n - 1);
    if (stoi(sortByType) == 1)
        quickSort("likes", listOfVideos, 0, n - 1);
    if (stoi(sortByType) == 1)
        quickSort("comments", listOfVideos, 0, n - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "QuickSort took " << duration.count() << " microseconds to complete.\n\n";
}
else if (stoi(algo) == 1) {
    auto start = std::chrono::high_resolution_clock::now();
    if (stoi(sortByType) == 1)
        heapSort("views", listOfVideos);
    else if (stoi(sortByType) == 2)
        heapSort("likes", listOfVideos);
    else if (stoi(sortByType) == 3)
        heapSort("comments", listOfVideos);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "HeapSort took " << duration.count() << " microseconds to complete.\n\n";
}

if (stoi(displayType) == 1)
{
    for (int i = 0; i < 10; i++)
        std::cout << i + 1 << ". " << listOfVideos[i].channel << std::endl;
}
else if (stoi(displayType) == 2)
{
    for (int i = 0; i < 10; i++)
        std::cout << i + 1 << ". " << listOfVideos[i].categoryName << std::endl;
}
else if (stoi(displayType) == 3)
{
    for (int i = 0; i < 10; i++)
        std::cout << i + 1 << ". " << listOfVideos[i].title << std::endl;
}

return 0;
}