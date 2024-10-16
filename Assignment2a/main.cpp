/*Pan Vladimir st128934@student.spbu.ru
  naive reverce of binary file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

int main()
{
    // Input path
    std::string filepath;
    std::cout << "input the path of the binary file: ";
    std::cin >> filepath;

    // Find out the size of the binary file
    std::filesystem::path path_obj(filepath);
    auto file_size = std::filesystem::file_size(path_obj);
    std::cout << "File size: " << file_size << " bytes\n";

    // Open the binary file, read it into a dynamically allocated buffer, then close it
    std::ifstream infile(filepath, std::ios::binary | std::ios::in);
    if (!infile.is_open()) {
        std::cerr << "Error: Could not open the file.\n";
    }

    // Dynamically allocate buffer for file content
    char* buffer = new char[file_size];
    infile.read(buffer, file_size);
    infile.close();

    // Naive reverse realization
    for (size_t i = 0; i < file_size / 2; ++i) {
        std::swap(buffer[i], buffer[file_size - i - 1]);
    }

    // Write the reversed to a new binfile
    std::ofstream outfile("reversed.bin", std::ios::binary);
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open output file.\n";
        delete[] buffer;
        return 1;
    }
    outfile.write(buffer, file_size);
    outfile.close();

    
    delete[] buffer;
    std::cout << "has been written to reversed.bin.\n";

    return 0;
}

