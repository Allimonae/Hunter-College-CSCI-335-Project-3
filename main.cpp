#include <iostream>
#include <fstream>
#include "StdSort.hpp"
#include "QuickSelect1.hpp"
#include "QuickSelect2.hpp"
#include "CountingSort.hpp"

int main(){
    // Read input file
    std::ifstream file("test_input.txt");
    if (file.fail()){
        std::cerr << "File cannnot be opened for reading" << std::endl;
        exit(1);
    }

    // Read the first line to get hender
    std::string header;
    getline(file, header); 

    // Read the second line to get values for data
    std::vector<int> data;
    std::string line;
    while (file >> line){
        data.push_back(stoi(line));
    }

    // stdSort(header, data);
    // quickSelect1(header, data);
    quickSelect2(header, data);
    // countingSort(header, data);
}