/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
 * InsertionSort is a helper for QuickSelect1 and QuickSelect2.
*/

#ifndef PROJECT_3_INSERTION_SORT
#define PROJECT_3_INSERTION_SORT

#include <iostream>
#include <vector>

/**
 * InsertionSort is called when quickSelect is called on a range of 20 or less elements, or when left + 20 > right
 * @param:  data is a vector of int values extracted from input file
 * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
 * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
 * @post:   Sorts the data in the range left to right in ascending order 
*/
void insertionSort(std::vector<int>& data, int left, int right);

#endif