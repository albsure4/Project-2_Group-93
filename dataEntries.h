//
// Created by ticol on 3/25/2026.
//

#ifndef DATAENTRIES_H
#define DATAENTRIES_H

#include <iostream>


class dataEntries {
std::string title;
int views;
int likes;
int comments;
int category;
std::string channel;
public:
    dataEntries(std::string Title, int Views, int Likes, int Comments, int Category, std::string Channel) : title(Title),
views(Views), likes(Likes), comments(Comments), category(Category), channel(Channel){};
};



#endif //DATAENTRIES_H
