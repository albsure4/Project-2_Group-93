# YouTube Trending Video Sorter

## Description
A C++ program that parses YouTube trending video datasets and sorts them by view count, like count, or comment count using HeapSort or QuickSort. Results display the top 10 videos by channel name, category, or video title.

## Dataset
The dataset was acquired from [Kaggle - YouTube Trending Video Dataset](https://www.kaggle.com/datasets/datasnaek/youtube-new) and the files can be found in the "Data" folder.

## How to Run
1. Clone the repository
2. Open the project in CLion and build using the default CMake configuration
3. Run the executable and follow the prompts

## Usage
The program will prompt you to select:
1. Country — which country's trending data to load (or all)
2. Sorting Algorithm — HeapSort or QuickSort
3. Sort By — View Count, Like Count, or Comment Count
4. Display By — Channel Name, Category, or Video Name

## NOTE: You must input the correct numbers for the program to execute properly. If not, the program will end. 
## For example, if you're given options 1-3, only enter "1" "2" or "3".

The top 10 results and the time taken to sort will be printed to the console.

