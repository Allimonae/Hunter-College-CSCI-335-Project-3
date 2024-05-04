#ifndef PROJECT_3_QUICKSELECT_2
#define PROJECT_3_QUICKSELECT_2

#include <iostream>
#include <vector>

void quickSelect2(const std::string& header, std::vector<int> data);
std::vector<int> quickSelect2Helper(std::vector<int>& data, int left, int right, std::vector<int> k);

#endif