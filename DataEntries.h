//
// Created by ticol on 3/25/2026.
//

#ifndef DATAENTRIES_H
#define DATAENTRIES_H

#include <iostream>
#include <utility>


struct dataEntries {
std::string title;
int views;
int likes;
int comments;
int category;
std::string categoryName;
std::string channel;

    dataEntries(std::string  Title,const int& Views,const int& Likes,const int& Comments,const int& Category, std::string  Channel) : title(std::move(Title)),
views(Views), likes(Likes), comments(Comments), category(Category), channel(std::move(Channel)) {
        if (category == 1)
            categoryName = "Film & Animation";
        if (category == 2)
            categoryName = "Autos & Vehicles";
        if (category == 10)
            categoryName = "Music";
        if (category == 15)
            categoryName = "Pets & Animals";
        if (category == 17)
            categoryName = "Sports";
        if (category == 18)
            categoryName = "Short Movies";
        if (category == 19)
            categoryName = "Travel & Events";
        if (category == 20)
            categoryName = "Gaming";
        if (category == 21)
            categoryName = "Videoblogging";
        if (category == 22)
            categoryName = "People & Blogs";
        if (category == 23)
            categoryName = "Comedy";
        if (category == 24)
            categoryName = "Entertainment";
        if (category == 25)
            categoryName = "News & Politics";
        if (category == 26)
            categoryName = "Howto & Style";
        if (category == 27)
            categoryName = "Education";
        if (category == 28)
            categoryName = "Science & Technology";
        if (category == 29)
            categoryName = "Nonprofits & Activism";
        if (category == 30)
            categoryName = "Movies";
        if (category == 31)
            categoryName = "Anime/Animation";
        if (category == 32)
            categoryName = "Action/Adventure";
        if (category == 33)
            categoryName = "Classics";
        if (category == 34)
            categoryName = "Comedy";
        if (category == 35)
            categoryName = "Documentary";
        if (category == 36)
            categoryName = "Drama";
        if (category == 37)
            categoryName = "Family";
        if (category == 38)
            categoryName = "Foreign";
        if (category == 39)
            categoryName = "Horror";
        if (category == 40)
            categoryName = "Sci-Fi/Fantasy";
        if (category == 41)
            categoryName = "Thriller";
        if (category == 42)
            categoryName = "Shorts";
        if (category == 43)
            categoryName = "Shows";
        if (category == 44)
            categoryName = "Trailers";
    };
};

#endif //DATAENTRIES_H
