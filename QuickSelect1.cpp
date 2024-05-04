#include <random>
#include <algorithm>
#include "QuickSelect1.hpp"
#include "InsertionSort.hpp"

void quickSelect1(const std::string& header, std::vector<int> data){
    int p50 = quickSelectHelper(data, 0, data.size() - 1, data.size()/2 - 1);
    auto middle = data.begin() + data.size()/2;
    std::partition(data.begin(), data.end(), [middle](int value){
        return value < *middle;
    });
    int p25 = quickSelectHelper(data, 0, data.size()/2 - 1, data.size()/4);
    int p75 = quickSelectHelper(data, data.size()/2, data.size() - 1, 3 * data.size()/4);
    auto bottom = data.begin() + data.size()/4;
    std::partition(data.begin(), data.end(), [bottom](int value){
        return value < *bottom;
    });
    int min = quickSelectHelper(data, 0, data.size()/4 - 1, 1);
    auto top = data.begin() + 3 * data.size()/4;
    std::partition(data.begin(), data.end(), [top](int value){
        return value < *top;
    });
    int max = quickSelectHelper(data, 3 * data.size()/4, data.size() - 1, data.size() - 1);
    std::cout << header
              << "\nMin: " << min
              << "\nP25: " << p25
              << "\nP50: " << p50
              << "\nP75: " << p75
              << "\nMax: " << max;
}

int quickSelectHelper(std::vector<int>& data, int left, int right, int k){
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

        if (k < i){
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

