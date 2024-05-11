/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
*/

#include <iostream>
#include <vector>

/**
 * std::sort is called and prints out the appropriate data points via direct access. 
 * This is used to ensure the correct answer and printing, and to give a baseline to time other algorithms against.
 * @param: string header is the first line of the input file
 * @param: data is a vector of integers converted from the input file
*/
void stdSort(const std::string& header, std::vector<int> data);