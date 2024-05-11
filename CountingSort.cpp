/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
*/

#include <algorithm>
#include <unordered_map>
#include <utility>
#include "CountingSort.hpp"

/**
 * Read the integers from the data vector and insert them into a hash map, with the data value as the hash key, and a count of times that data value was seen as the hash value. 
 * Once there is a hash map of all the unique data values and the number of times each data value appeared in the data, iterate through the hash map, pushing the key-value pairs in the hash map to a vector. 
 * Then, sort that vector using std::sort  
 * Finally, iterate through that vector finding P25, P50, and P75. 
 * @param: string header is the first line of the input file
 * @param: data is a vector of integers converted from the input file
*/
void countingSort(const std::string& header, std::vector<int> data){
    // the key of countMap is a unique value, the value of countMap is the number of occurences
    std::unordered_map<int, int> countMap;
    
    // add values to countMap and keep track of how many unique values
    int unique = 0;
    for (auto i : data){
        if (countMap.find(i) == countMap.end()){
            unique++; // unique increments every first instance of a value 
        }
        countMap[i]++;
    }

    // add pairs of keys and values from countMap to countVector
    std::vector<std::pair<int, int>> countVector;
    for (auto j : countMap){
        std::pair<int, int> keyValue;
        keyValue.first = j.first;
        keyValue.second = j.second;
        countVector.push_back(keyValue);
    }

    // sort countVector in ascending order according to first values
    std::sort(countVector.begin(), countVector.end(), [](std::pair<int, int> a, std::pair<int,int> b){return a.first < b.first;});
    
    // get indices of median, p25, and p75
    int median_index = (data.size() - 1)/2;
    int p25_index = (median_index)/2;
    int p75_index = (median_index + data.size())/2;

    // print minimum
    std::cout << header 
              << "\nMin: " << countVector[0].first;

    // iterate through countVector and print values when indices are met
    int count = 0;
    for (auto k : countVector){
        // iterate through number of instances of a key value
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

    // print maximum
    std::cout << "\nMax: " << countVector[countVector.size() - 1].first
              << "\nUnique: " << unique << std::endl;
}