#include "InsertionSort.hpp"

void insertionSort(std::vector<int>& data, int left, int right){
    for (int p = left + 1; p < right + 1; ++p)
    {
        int tmp = std::move(data[p]);
        
        int j;
        for (j = p; j > left && tmp < data[j - 1]; --j)
            data[j] = std::move(data[j - 1]);
        data[j] = std::move(tmp);
    }
}