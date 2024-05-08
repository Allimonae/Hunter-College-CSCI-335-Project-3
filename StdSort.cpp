#include <algorithm>
#include "StdSort.hpp"

void stdSort(const std::string& header, std::vector<int> data){
    std::sort(data.begin(), data.end());
    int median_index = (data.size())/2 - 1;
    std::cout << median_index << " ";
    int p25_index = (median_index)/2;
    std::cout << p25_index << " ";
    int p75_index = (median_index + data.size())/2;
    std::cout << p75_index << std::endl;

    std::cout << header
              << "\nMin: " << data[0]
              << "\nP25: " << data[p25_index]
              << "\nP50: " << data[median_index]
              << "\nP75: " << data[p75_index]
              << "\nMax: " << data[data.size() - 1] << std::endl;
}