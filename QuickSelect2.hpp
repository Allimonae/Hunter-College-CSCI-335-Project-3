/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
*/

#ifndef PROJECT_3_QUICKSELECT_2
#define PROJECT_3_QUICKSELECT_2

#include <iostream>
#include <vector>

/**
 * replace the key k in quickSelect1's parameters with a set of keys you're looking for (using a vector)
 * This vector includes position 0, the 25% mark, the 50% mark, the 75% mark, the the last position of the data vector. 
 * The recursive portion of quickSelect is modified so that it checks whether it needs to recurse on both sides (if there are keys you need to find on both sides of the range being called), 
 *      or if it only needs to recurse on one side. 
 * Default to insertion sort once it reaches a size of 20 or less. 
 * @param: string header is the first line of the input file
 * @param: data is a vector of integers converted from the input file
*/
void quickSelect2(const std::string& header, std::vector<int> data);

/**
 * modified from the textbook: Data Structions and Algorithms in C++ 4th edition by Mark Allen Weiss p. 322
 * @param:  data is a vector of int values extracted from input file
 * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
 * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
 * @param:  keys is a vector of indices of the desired elements to be found
 * @post:   Paritions values in data according to the pivot, found by median3 algorithm
 *          Iterates through keys to find if there are indices to be found in the partition
 *          Makes recursive calls to partitions according to if indices in keys are in range of left and right
 *          When the range of left and right is 20 or less, it defaults to insertion sort, so the values around the index of the vector are sorted
*/
void quickSelect2Helper(std::vector<int>& data, int left, int right, std::vector<int>& keys);

/**
 * modified from the textbook: Data Structions and Algorithms in C++ 4th edition by Mark Allen Weiss p. 316
" * Return median of left, center, and right.
  * Order these and hide the pivot. " (Weiss, 316)
  * @param:  data is a vector of int values extracted from input file
  * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
  * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
*/
int median3(std::vector<int> & data, int left, int right);

#endif