//
// Created by ticol on 3/26/2026.
//

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <iostream>
#include <vector>
#include "DataEntries.h"

//helper function to swap two videos within the vector of videos
void swap(std::vector<dataEntries>& listOfVideos, int index1, int index2) {
    dataEntries temp = listOfVideos[index1];
    listOfVideos[index1] = listOfVideos[index2];
    listOfVideos[index2] = temp;
}

//Referenced DSA Sp26 - Thu Lecture-  Mar 5 , 2026 09:34 AM
//selects a pivot point and sorts listOfVideos in descending order
int partition(const std::string& type, std::vector<dataEntries>& listOfVideos, int low, int high) {
    if (type == "views") {
        int pivot = listOfVideos[low].views;
        int up = low + 1;
        int down = high;

        while (up <= down) {
            while (up <= high && listOfVideos[up].views > pivot) {
                up++;
            }
            while (down > low && listOfVideos[down].views < pivot) {
                down--;
            }
            if (up < down) {
                swap(listOfVideos, up, down);
                up++;
                down--;
            }
            else {
                break;
            }
        }
        swap(listOfVideos, low, down);
        return down;
    }
    if (type == "likes") {
        int pivot = listOfVideos[low].likes;
        int up = low + 1;
        int down = high;

        while (up <= down) {
            while (up <= high && listOfVideos[up].likes > pivot) {
                up++;
            }
            while (down > low && listOfVideos[down].likes < pivot) {
                down--;
            }
            if (up < down) {
                swap(listOfVideos, up, down);
                up++;
                down--;
            }
            else {
                break;
            }
        }
        swap(listOfVideos, low, down);
        return down;
    }
    if (type == "comments") {
        int pivot = listOfVideos[low].comments;
        int up = low + 1;
        int down = high;

        while (up <= down) {
            while (up <= high && listOfVideos[up].comments > pivot) {
                up++;
            }
            while (down > low && listOfVideos[down].comments < pivot) {
                down--;
            }
            if (up < down) {
                swap(listOfVideos, up, down);
                up++;
                down--;
            }
            else {
                break;
            }
        }
        swap(listOfVideos, low, down);
        return down;
    }
    return low;
}

//recursive function to run each pass of the quicksort method and sort in descending order by type
void quickSort(const std::string& type, std::vector<dataEntries>& listOfVideos, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(type, listOfVideos, low, high);
        quickSort(type, listOfVideos, low, pivotIndex - 1);
        quickSort(type, listOfVideos, pivotIndex + 1, high);
    }
}

#endif // QUICKSORT_H
