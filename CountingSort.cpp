#include <algorithm>
#include <map>
#include "CountingSort.hpp"

void countingSort(const std::string& header, std::vector<int> data){
    std::map<int, int> countMap;
    int unique = 0;
    for (auto i : data){
        if (countMap.find(i) == countMap.end()){
            unique++;
        }
        countMap[i]++;
    }
    std::vector<int> countVector;
    for (auto j : countMap){
        for (int i = 0; i < j.second; i++){
            countVector.push_back(j.first);
        } 
    }
    // for (auto k : countVector){
    //     std::cout << k << std::endl;
    // }
    int median_index = (data.size() - 1)/2;
    int p25_index = (median_index)/2;
    int p75_index = (median_index + data.size())/2;
    std::cout << header
              << "\nMin: " << countVector[0]
              << "\nP25: " << countVector[p25_index]
              << "\nP50: " << countVector[median_index]
              << "\nP75: " << countVector[p75_index]
              << "\nMax: " << countVector[data.size() - 1] 
              << "\nUnique: " << unique << std::endl;
}