//
// Created by ticol on 3/26/2026.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

#endif //QUICKSORT_H
//
// Created by ticol on 3/26/2026.
//
#include <iostream>
#include <vector>
#include "DataEntries.h"


void swap(std::vector<dataEntries>& listOfVideos, int index1, int index2) {
    dataEntries temp(listOfVideos[index1].title, listOfVideos[index1].views, listOfVideos[index1].likes, listOfVideos[index1].comments, listOfVideos[index1].category, listOfVideos[index1].channel);
    listOfVideos[index1] = listOfVideos[index2];
    listOfVideos[index2] = temp;
}



//Referenced DSA Sp26 - Thu Lecture-  Mar 5 , 2026 09:34 AM
int partition(const std::string& type, std::vector<dataEntries>& listOfVideos, int low, int high) {

    if (type == "views") {
        int pivot = listOfVideos[low].views;
        int up = low, down = high;

        while(up < down) {
            for(int i = up; i < high; i++) {
                if(listOfVideos[up].views > pivot) {
                    break;
                }
                up++;
            }
            for (int i = high; i > low; i++) {
                if(listOfVideos[down].views < pivot) {
                    break;
                }
                down--;
            }
            if(up < down) {
                swap(listOfVideos, up, down);
            }
        }
        swap(listOfVideos, low, down);
        return down;
    }
    if (type == "likes") {
        int pivot = listOfVideos[low].likes;
        int up = low, down = high;

        while(up < down) {
            for(int i = up; i < high; i++) {
                if(listOfVideos[up].likes > pivot) {
                    break;
                }
                up++;
            }
            for (int i = high; i > low; i++) {
                if(listOfVideos[down].likes < pivot) {
                    break;
                }
                down--;
            }
            if(up < down) {
                swap(listOfVideos, up, down);
            }
        }
        swap(listOfVideos, low, down);
        return down;
    }
    if (type == "comments") {
        int pivot = listOfVideos[low].comments;
        int up = low, down = high;

        while(up < down) {
            for(int i = up; i < high; i++) {
                if(listOfVideos[up].comments > pivot) {
                    break;
                }
                up++;
            }
            for (int i = high; i > low; i++) {
                if(listOfVideos[down].comments < pivot) {
                    break;
                }
                down--;
            }
            if(up < down) {
                swap(listOfVideos, up, down);
            }
        }
        swap(listOfVideos, low, down);
        return down;
    }
}


void quickSort(const std::string& type, std::vector<dataEntries>& listOfVideos, int low, int high) {
    if(low < high) {
        if (type == "views") {
            int pivot = partition(type, listOfVideos, low, high);
            quickSort(type, listOfVideos, low, pivot - 1);
            quickSort(type, listOfVideos, pivot + 1, high);
        }
    }
}

