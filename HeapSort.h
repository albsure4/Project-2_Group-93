//
// Created by Tanner Fulwider on 3/27/26.
//

#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "DataEntries.h"

//restores heap order
void heapifyDown(const std::string& type, std::vector<dataEntries>& videos, int index, int size)
{

	while (true)
	{
		int smallest = index;
		int left = 2*index + 1;
		int right = 2*index + 2;

		if (type == "views")
		{
			if (left < size && videos[left].views < videos[smallest].views)
				smallest = left;
			if (right < size && videos[right].views < videos[smallest].views)
				smallest = right;
		}
		else if (type == "likes")
		{
			if (left < size && videos[left].likes < videos[smallest].likes)
				smallest = left;
			if (right < size && videos[right].likes < videos[smallest].likes)
				smallest = right;
		}
		else if (type == "comments")
		{
			if (left < size && videos[left].comments < videos[smallest].comments)
				smallest = left;
			if (right < size && videos[right].comments < videos[smallest].comments)
				smallest = right;
		}

		if (index == smallest)
			break;

		std::swap(videos[smallest], videos[index]);
		index = smallest;
	}
}

//swaps minimum element to heap end then restores heap order
void extractMin(const std::string& type, std::vector<dataEntries>& videos, int size)
{
	std::swap(videos[0], videos[size - 1]);
	heapifyDown(type, videos, 0, size - 1);
}

//Sorts videos in descending order through a min-heap and extracting min
void heapSort(const std::string& type, std::vector<dataEntries>& videos)
{
	for (int i = videos.size()/2 - 1; i >= 0; i--)
		heapifyDown(type, videos, i, videos.size());

	int size = videos.size();

	while (size > 0)
	{
		extractMin(type, videos, size);
		size--;
	}
}