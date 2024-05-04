#ifndef PROJECT_3_QUICKSELECT_1
#define PROJECT_3_QUICKSELECT_1

#include <iostream>
#include <vector>

void quickSelect1(const std::string& header, std::vector<int> data);
int quickSelectHelper(std::vector<int>& data, int left, int right, int k);

#endif