#include <algorithm>
#include <unordered_map>
#include <utility>
#include "CountingSort.hpp"

void countingSort(const std::string& header, std::vector<int> data){
    std::unordered_map<int, int> countMap;
    int unique = 0;
    for (auto i : data){
        if (countMap.find(i) == countMap.end()){
            unique++;
        }
        countMap[i]++;
    }
    std::vector<std::pair<int, int>> countVector;
    for (auto j : countMap){
        std::pair<int, int> keyValue;
        keyValue.first = j.first;
        keyValue.second = j.second;
        countVector.push_back(keyValue);
    }
    std::sort(countVector.begin(), countVector.end(), [](std::pair<int, int> a, std::pair<int,int> b){return a.first < b.first;});
    // for (auto k : countVector){
    //     std::cout << k << std::endl;
    // }
    int median_index = (data.size() - 1)/2;
    int p25_index = (median_index)/2;
    int p75_index = (median_index + data.size())/2;

    std::cout << header 
              << "\nMin: " << countVector[0].first;

    int count = 0;
    for (auto k : countVector){
        for (int i = 0; i < k.second; i++){
            if (count == p25_index){
                std::cout << "\nP25: " << k.first;
            } 
            else if (count == median_index){
                std::cout << "\nP50: " << k.first;
            } 
            else if (count == p75_index){
                std::cout << "\nP75: " << k.first;
            }
            count++;
        } 
    }

    std::cout << "\nMax: " << countVector[countVector.size() - 1].first
              << "\nUnique: " << unique << std::endl;
}