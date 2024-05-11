/**
 * CSCI 335 Project 3
 * Spring 2024
 * Created by Allison Lee
*/

#ifndef PROJECT_3_COUNTING_SORT
#define PROJECT_3_COUNTING_SORT

#include <iostream>
#include <vector>

/**
 * Read the integers from the data vector and insert them into a hash map, with the data value as the hash key, and a count of times that data value was seen as the hash value. 
 * Once there is a hash map of all the unique data values and the number of times each data value appeared in the data, iterate through the hash map, pushing the key-value pairs in the hash map to a vector. 
 * Then, sort that vector using std::sort  
 * Finally, iterate through that vector finding P25, P50, and P75. 
 * @param: string header is the first line of the input file
 * @param: data is a vector of integers converted from the input file
*/
void countingSort(const std::string& header, std::vector<int> data);

#endif