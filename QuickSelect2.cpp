#include <algorithm>
#include "QuickSelect2.hpp"
#include "InsertionSort.hpp"

void quickSelect2(const std::string& header, std::vector<int> data){
    std::vector<int> k = {1, (int)data.size()/4, (int)data.size()/2, 3 * (int)data.size()/4, (int)data.size()};
}

std::vector<int> quickSelect2Helper(std::vector<int>& data, int left, int right, std::vector<int> k){
    std::vector<int> selected;
    if (left + 20 <= right){
        std::vector<int> pivotarray = {data[(left + right)/2], data[left], data[right]};
        std::sort(pivotarray.begin(), pivotarray.end());
        int pivot = pivotarray[1];        
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

        // if (k < i){
        //     quickSelect2Helper(data, left, i - 1, k);
        // }
        // else if (k > i + 1){
        //     quickSelect2Helper(data, i + 1, right, k);
        // }
        // else {
        //     selected.push_back(data[i]);
        // }
    }
    else {
        insertionSort(data, left, right);
        //selected.push_back(data[k-1]);
    }
    if (k.empty()){
        return selected;
    }
}