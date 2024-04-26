#include <random>
#include <algorithm>
#include "QuickSelect1.hpp"

void quickSelect1(const std::string& header, std::vector<int> data){
    std::cout << quickSelectHelper(data);
}

int quickSelectHelper(std::vector<int> data, int left, int right, int k){
    if (left + 10 <= right){
        std::vector<int> pivotarray = {data[data.size()/2], left, right};
        std::sort(pivotarray.begin(), pivotarray.end());
        int pivot = pivotarray[1];

        for ( ; ; ){
            while(data[++i] < pivot){}
            while(pivot < data[--j]){}
        }
    }

    std::cout << "hey: " << data.size() << std::endl;
    if (data.size() == 1){
        return data[0];
    }
    
    int k = data.size()/2;
    int randnum = rand() % data.size(); // randnum is a random number in data.size()
    int pivot = data[randnum];
    std::vector<int> partitionA;
    std::vector<int> partitionB;
    for (auto it : data){
        if (it < pivot){
            partitionA.push_back(it);
        }
        else {
            partitionB.push_back(it);
        }
    }
}