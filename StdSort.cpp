#include <algorithm>
#include "StdSort.hpp"

void stdSort(const std::string& header, std::vector<int> data){
    std::sort(data.begin(), data.end());
    std::cout << header
              << "\nMin: " << data[0]
              << "\nP25: " << data[data.size()/4 - 1]
              << "\nP50: " << data[data.size()/2 - 1]
              << "\nP75: " << data[3 * data.size()/4 - 1]
              << "\nMax: " << data[data.size() - 1];
}