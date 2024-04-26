#include <random>
#include "QuickSelect1.hpp"

void quickSelect1(const std::string& header, std::vector<int> data){
    std::cout << quickSelectHelper(data);
}

int quickSelectHelper(std::vector<int> data){
    std::cout << "hey";
    if (data.size() == 1){
        return data[0];
    }

    int k = data.size()/2;
    if (data.size() % 2 == 1){ // if data size is odd
        k += 1; 
    }
    
    int pivot = data[k];
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
    if (partitionA.size() > k){
        return quickSelectHelper(partitionA);
    }
    else {
        return quickSelectHelper(partitionB);
    }
}