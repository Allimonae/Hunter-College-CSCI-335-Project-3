/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
 * 
*/

#include <algorithm>
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"

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
void quickSelect1(const std::string& header, std::vector<int> data){
    quickSelect1Helper(data, 0, data.size() - 1, data.size()/2);
    quickSelect1Helper(data, 0, data.size()/2 - 1, data.size()/4);
    quickSelect1Helper(data, data.size()/2, data.size() - 1, 3 * data.size()/4);
    quickSelect1Helper(data, 0, data.size()/4 - 1, 1);
    quickSelect1Helper(data, 3 * data.size()/4, data.size() - 1, data.size());

    std::cout << header
              << "\nMin: " << data[0]
              << "\nP25: " << data[data.size()/4 - 1]
              << "\nP50: " << data[data.size()/2 - 1]
              << "\nP75: " << data[3 * data.size()/4 - 1]
              << "\nMax: " << data[data.size() - 1] << std::endl;
}

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
void quickSelect1Helper(std::vector<int>& data, int left, int right, int k)
{
    // if range is 20 or less, default to insertion sort
    if (left + 20 <= right)
    {
        const int& pivot = medianof3(data, left, right);

        // Begin partitioning
        int i = left;
        int j = right - 1;

        for( ; ; )
        {           
            while(data[++i] < pivot){ }
            while(pivot < data[--j]){ }
            
            if (i < j)
                std::swap(data[i], data[j]);
            else 
                break;
        }

        std::swap(data[i], data[right - 1]); // Restore pivot
        // end partitioning

        // Recurse on one side depending on k's relation to the pivot
        if (k <= i)
            quickSelect1Helper(data, left, i - 1, k);
        else if (k > i + 1)
            quickSelect1Helper(data, i + 1, right, k);
    }
    else 
        insertionSort(data, left, right);
}

/**
 * modified from the textbook: Data Structions and Algorithms in C++ 4th edition by Mark Allen Weiss p. 316
" * Return median of left, center, and right.
  * Order these and hide the pivot. " (Weiss, 316)
  * @param:  data is a vector of int values extracted from input file
  * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
  * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
*/
int medianof3(std::vector<int> & a, int left, int right){
    int center = ( left + right ) / 2;

    // make swaps to order left, right, and center values to take the median
    if (a[center] < a[left])
        std::swap( a[left], a[center]);
    if (a[right] < a[left])
        std::swap( a[ left ], a[right]); 
    if (a[right] < a[center])
        std::swap(a[center], a[right]);
        
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}
