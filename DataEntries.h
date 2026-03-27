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
std::string channel;

    dataEntries(std::string  Title,const int& Views,const int& Likes,const int& Comments,const int& Category, std::string  Channel) : title(std::move(Title)),
views(Views), likes(Likes), comments(Comments), category(Category), channel(std::move(Channel)){};
};



#endif //DATAENTRIES_H
