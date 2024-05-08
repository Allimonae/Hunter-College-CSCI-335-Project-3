#include <algorithm>
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"

void quickSelect2(const std::string& header, std::vector<int> data){
    std::vector<int> k = {1, (int)data.size()/4, (int)data.size()/2, 3 * (int)data.size()/4, (int)data.size()};
}

std::vector<int> quickSelect2Helper(std::vector<int>& data, int left, int right, std::vector<int> k){
    if (left + 20 <= right){
        int pivot = median3(data, left, right);
        int i = left;
        int j = right - 1;
        while (true){           
            while(data[i] < pivot) {
                i++;
            }
            while(pivot < data[j]) {
                j--;
            }
            if (i < j){
                std::swap(data[i], data[j]);
                i++;
                j--;
            }
            else {
                break;
            }
        }
        std::swap(data[i], data[right - 1]);
    }
    //     if (k < i){
    //         return quickSelectHelper(data, left, i - 1, k);
    //     }
    //     else if (k > i + 1){
    //         return quickSelectHelper(data, i + 1, right, k);
    //     }
    //     else {
    //         return data[i];
    //     }
    // }
    // else {
    //     insertionSort(data, left, right);
    //     return data[k - 1];
    // }
}

/**
 * Return median of left, center, and right.
 * Order these and hide the pivot.
 */
int median3(std::vector<int> & a, int left, int right){
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

