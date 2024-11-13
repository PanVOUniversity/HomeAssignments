#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <lab1.h>

std::tuple <std::vector<char>, std::streamsize> readFileAsBinary(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate); // places the read position at the end 
    if (!file) throw std::runtime_error("Could not open file"); 

    std::streamsize size = file.tellg(); 
    file.seekg(0, std::ios::beg); //places the read position to 0

    std::vector<char> buffer(size);
    if (!file.read(buffer.data(), size)) throw std::runtime_error("Could not read file");

    return make_tuple(buffer,size);
}

int main() {
    std::string path;
    std::cin >> path;
    std::tuple<std::vector<char>, std::streamsize> result = readFileAsBinary(path); // read file
    std::vector<char> buffer = std::get<0>(result);
    std::streamsize size = std::get<1>(result);
    char* bin_img = buffer.data(); //allocating in memory
    
    //writing array into file
    std::ofstream file("output.txt");

    for (size_t i = 0; i < buffer.size(); ++i) {
        file << bin_img[i];
        if (i != buffer.size() - 1) {
            file << " ";  // Add space between elements
    }
}

