#include <algorithm>
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"

void quickSelect2(const std::string& header, std::vector<int> data)
{
    int median_index = data.size()/2;
    int p25_index = median_index/2;
    int p75_index = (median_index + data.size())/2;
    // int median_index = (data.size())/2 - 1;
    // int p25_index = (median_index)/2;
    // int p75_index = (median_index + data.size())/2;
    

    std::vector<int> keys = {0, p25_index - 1, median_index - 1, p75_index - 1, 1000};
    quickSelect2Helper(data, 0, data.size() - 1, keys);
    for (int i = 0; i < data.size(); i++){
        std::cout << i << ": " << data[i] << std::endl;
    }
    std::cout << header
              << "\nMin: " << data[0]
              << "\nP25: " << data[p25_index - 1]
              << "\nP50: " << data[median_index - 1]
              << "\nP75: " << data[p75_index - 1]
              << "\nMax: " << data[data.size() - 1] << std::endl;
}

void quickSelect2Helper(std::vector<int>& data, int left, int right, std::vector<int>& keys)
{
    if (left + 20 <= right)
    {
        const int& pivot = median3(data, left, right);
        
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
        // partition: return i

        std::vector<int> keysInRange;
        for (auto key : keys) {
            if (key >= left && key <= right)
                keysInRange.push_back(key);
        }

        if (!keysInRange.empty()) {
            for (auto key : keysInRange) {
                if (key == i + 1){
                    std::cout << "Element at position " << key << ": " << data[i] << std::endl;
                }
                if (key <= i) {
                    quickSelect2Helper(data, left, i - 1, keys);
                } 
                else if (key > i + 1){
                    quickSelect2Helper(data, i + 1, right, keys);
                }
            }
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
int median3(std::vector<int>& data, int left, int right){
    int center = ( left + right ) / 2;

    if (data[center] < data[left])
        std::swap( data[left], data[center]);
    if (data[right] < data[left])
        std::swap( data[ left ], data[right]); 
    if (data[right] < data[center])
        std::swap(data[center], data[right]);
        
    std::swap(data[center], data[right - 1]);
    return data[right - 1];
}

