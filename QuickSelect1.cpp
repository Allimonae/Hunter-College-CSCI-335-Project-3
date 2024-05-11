/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
 * 
*/
#include <algorithm>
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"

void quickSelect1(const std::string& header, std::vector<int> data){
    quickSelect1Helper(data, 0, data.size() - 1, data.size()/2);
    
    auto middle = data.begin() + data.size()/2;
    std::partition(data.begin(), data.end(), [middle](int value){
        return value < *middle;
    });
    std::vector<int> first_half(data.begin(), data.begin() + data.size()/2);
    std::vector<int> second_half(data.begin() + data.size()/2, data.end());
    quickSelect1Helper(first_half, 0, first_half.size() - 1, first_half.size()/2);
    quickSelect1Helper(second_half, 0, second_half.size() - 1, second_half.size()/2);
    
    auto bottom = first_half.begin() + first_half.size()/2;
    std::partition(first_half.begin(), first_half.end(), [bottom](int value){
        return value < *bottom;
    });
    std::vector<int> lower_quarter(first_half.begin(), first_half.begin() + first_half.size()/2);
    quickSelect1Helper(lower_quarter, 0, lower_quarter.size() - 1, 1);
    
    auto top = second_half.begin() + second_half.size()/2;
    std::partition(second_half.begin(), second_half.end(), [top](int value){
        return value < *top;
    });
    std::vector<int> upper_quarter(second_half.begin() + second_half.size()/2, second_half.end());
    quickSelect1Helper(upper_quarter, 0, upper_quarter.size() - 1, upper_quarter.size());

    std::cout << header
              << "\nMin: " << lower_quarter[0]
              << "\nP25: " << first_half[first_half.size()/2 - 1]
              << "\nP50: " << data[data.size()/2 - 1]
              << "\nP75: " << second_half[second_half.size()/2 - 1]
              << "\nMax: " << upper_quarter[upper_quarter.size() - 1] << std::endl;
}

/**
 * 
 * @param:  data is a vector of int values extracted from input file
 * @param:  left is an int value indicating the index where the subarray starts, calculated from quickSelect
 * @param:  right is an int value indicating the index where the subarray ends, calculated from quickSelect
 * @post:   
*/
void quickSelect1Helper(std::vector<int>& data, int left, int right, int k)
{
    if (left + 20 <= right)
    {
        const int& pivot = medianof3(data, left, right);
        
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

        if (k <= i){
            quickSelect1Helper(data, left, i - 1, k);
        }
        else if (k > i + 1){
            quickSelect1Helper(data, i + 1, right, k);
        }
    }
    else {
        insertionSort(data, left, right);
    }
}

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
int medianof3(std::vector<int> & a, int left, int right){
    int center = ( left + right ) / 2;

    if (a[center] < a[left])
        std::swap( a[left], a[center]);
    if (a[right] < a[left])
        std::swap( a[ left ], a[right]); 
    if (a[right] < a[center])
        std::swap(a[center], a[right]);
        
    std::swap(a[center], a[right - 1]);
    return a[right - 1];
}
