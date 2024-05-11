/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
*/

#ifndef PROJECT_3_QUICKSELECT_1
#define PROJECT_3_QUICKSELECT_1

#include <iostream>
#include <vector>

/**
 * call quickSelect on the entire input with the middle of the vector as the key, k. 
 * This will give the median, around which your vector will be partitioned. 
 * Then, call quickSelect on the half of the vector before the median with the 25% mark of the vector as k. 
 * Then, call quickSelect on the half of the vector after the median with the 75% mark as k. 
 * Then, search for the minimum only before the 25% mark, and the maximum only after the 75% mark. 
 * Default to insertion sort when quickSelect is recursively called on a range of size 20 or less (this means you'll have to write a small in-place insertion sort).
 * @param: string header is the first line of the input file
 * @param: data is a vector of integers converted from the input file
*/
void quickSelect1(const std::string& header, std::vector<int> data);

/**
 * modified from the textbook: Data Structions and Algorithms in C++ 4th edition by Mark Allen Weiss p. 322
 * @param:  data is a vector of int values extracted from input file
 * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
 * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
 * @param:  k is the index of the desired element to be found
 * @post:   Paritions values in data according to the pivot, found by median3 algorithm
 *          Makes recursive calls to one side of the partition according to k in relation to the pivot
 *          When the range of left and right is 20 or less, it defaults to insertion sort, so the values around the index of the vector are sorted
*/
void quickSelect1Helper(std::vector<int>& data, int left, int right, int k);

/**
 * modified from the textbook: Data Structions and Algorithms in C++ 4th edition by Mark Allen Weiss p. 316
" * Return median of left, center, and right.
  * Order these and hide the pivot. " (Weiss, 316)
  * @param:  data is a vector of int values extracted from input file
  * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
  * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
*/
int medianof3(std::vector<int> & a, int left, int right);

#endif