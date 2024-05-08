#include <random>
#include <algorithm>
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"

void quickSelect1(const std::string& header, std::vector<int> data){
    int median_index = (data.size())/2;
    int p25_index = (median_index)/2;
    int p75_index = (median_index + data.size())/2;
    int p50 = quickSelectHelper(data, 0, data.size() - 1, median_index);
    
    auto middle = data.begin() + data.size()/2;
    std::partition(data.begin(), data.end(), [middle](int value){
        return value < *middle;
    });
    int p25 = quickSelectHelper(data, 0, data.size()/2 - 1, p25_index);
    int p75 = quickSelectHelper(data, data.size()/2, data.size() - 1, p75_index);
    
    auto bottom = data.begin() + data.size()/4;
    std::partition(data.begin(), data.end(), [bottom](int value){
        return value < *bottom;
    });
    int min = quickSelectHelper(data, 0, data.size()/4 - 1, 1);
    
    auto top = data.begin() + 3 * data.size()/4;
    std::partition(data.begin(), data.end(), [top](int value){
        return value < *top;
    });
    int max = quickSelectHelper(data, 3 * data.size()/4, data.size() - 1, data.size());
    
    std::cout << header
              << "\nMin: " << min
              << "\nP25: " << p25
              << "\nP50: " << p50
              << "\nP75: " << p75
              << "\nMax: " << max << std::endl;
}

int quickSelectHelper(std::vector<int>& data, int left, int right, int k)
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
            return quickSelectHelper(data, left, i - 1, k);
        }
        else if (k > i + 1){
            return quickSelectHelper(data, i + 1, right, k);
        }
        else {
            return data[i];
        }
    }
    else {
        insertionSort(data, left, right);
        return data[k - 1];
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
