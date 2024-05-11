/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
*/

#include <algorithm>
#include "StdSort.hpp"

/**
 * std::sort is called and prints out the appropriate data points via direct access. 
 * This is used to ensure the correct answer and printing, and to give a baseline to time other algorithms against.
 * @param: string header is the first line of the input file
 * @param: data is a vector of integers converted from the input file
*/
void stdSort(const std::string& header, std::vector<int> data){
    std::sort(data.begin(), data.end());

    // get indices of median, p25, and p75
    int median_index = (data.size())/2 - 1;
    int p25_index = (median_index)/2;
    int p75_index = (median_index + data.size())/2;
    
    std::cout << header
              << "\nMin: " << data[0]
              << "\nP25: " << data[p25_index]
              << "\nP50: " << data[median_index]
              << "\nP75: " << data[p75_index]
              << "\nMax: " << data[data.size() - 1] << std::endl;
}