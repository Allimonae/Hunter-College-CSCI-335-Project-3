/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
 * InsertionSort is a used in QuickSelect1 and QuickSelect2.
*/
#include "InsertionSort.hpp"

/**
 * modified from the textbook: Data Structions and Algorithms in C++ 4th edition by Mark Allen Weiss p. 293
 * InsertionSort is called when quickSelect is called on a range of 20 or less elements, or when left + 20 > right
 * @param:  data is a vector of int values extracted from input file
 * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
 * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
 * @post:   Sorts the data in the range left to right in ascending order 
*/
void insertionSort(std::vector<int>& data, int left, int right){
    // Traverse data from index left to right + 1
    for (int p = left + 1; p < right + 1; ++p)
    {
        int tmp = std::move(data[p]);

        int j;
        for (j = p; j > left && tmp < data[j - 1]; --j)
            data[j] = std::move(data[j - 1]);
        data[j] = std::move(tmp);
    }
}