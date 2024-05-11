/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
*/

#include <algorithm>
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"

/**
 * replace the key k in quickSelect1's parameters with a set of keys you're looking for (using a vector)
 * This vector includes position 0, the 25% mark, the 50% mark, the 75% mark, the the last position of the data vector. 
 * The recursive portion of quickSelect is modified so that it checks whether it needs to recurse on both sides (if there are keys you need to find on both sides of the range being called), 
 *      or if it only needs to recurse on one side. 
 * Default to insertion sort once it reaches a size of 20 or less. * @param: string header is the first line of the input file
 * @param: data is a vector of integers converted from the input file
*/
void quickSelect2(const std::string& header, std::vector<int> data)
{
    int median_index = data.size()/2;
    int p25_index = median_index/2;
    int p75_index = (median_index + data.size())/2;

    std::vector<int> keys = {1, p25_index, median_index, p75_index, (int)data.size()};
    quickSelect2Helper(data, 0, data.size() - 1, keys);
    
    std::cout << header
              << "\nMin: " << data[0]
              << "\nP25: " << data[p25_index - 1]
              << "\nP50: " << data[median_index - 1]
              << "\nP75: " << data[p75_index - 1]
              << "\nMax: " << data[data.size() - 1] << std::endl;
}

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
void quickSelect2Helper(std::vector<int>& data, int left, int right, std::vector<int>& keys)
{
    // if range is 20 or less, default to insertion sort
    if (left + 20 <= right)
    {
        const int& pivot = median3(data, left, right);
        
        // Begin partitioning
        int i = left;
        int j = right - 1;

        for( ; ; ){           
            while(data[++i] < pivot){ }
            while(pivot < data[--j]){ }
            
            if (i < j)
                std::swap(data[i], data[j]);
            else 
                break;
        }

        std::swap(data[i], data[right - 1]); // Restore pivot
        // end partitioning

        // iterate through keys to see if there are indices within range to be checked
        std::vector<int> keysToCheck;
        for (auto key : keys) {
            if (key >= left && key <= right + 1)
                keysToCheck.push_back(key);
        }

        // iterate through keysToCheck and recurse on the left or right side according to the key's relation to i
        for (auto key : keysToCheck) {
            if (key <= i) {
                quickSelect2Helper(data, left, i - 1, keys);
            } 
            else if (key > i + 1){
                quickSelect2Helper(data, i + 1, right, keys);
            }
        }
    }
    else {
        insertionSort(data, left, right);
    }
}


/**
 * modified from the textbook: Data Structions and Algorithms in C++ 4th edition by Mark Allen Weiss p. 316
" * Return median of left, center, and right.
  * Order these and hide the pivot. " (Weiss, 316)
  * @param:  data is a vector of int values extracted from input file
  * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
  * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
*/
int median3(std::vector<int>& data, int left, int right){
    int center = ( left + right ) / 2;

    // make swaps to order left, right, and center values to take the median
    if (data[center] < data[left])
        std::swap( data[left], data[center]);
    if (data[right] < data[left])
        std::swap( data[ left ], data[right]); 
    if (data[right] < data[center])
        std::swap(data[center], data[right]);
        
    std::swap(data[center], data[right - 1]);
    return data[right - 1];
}

