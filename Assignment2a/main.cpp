#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
std::ifstream infile;

int main()
	{
		std::string a;
		std::cout << "input path, pls \n";
		std::cin >> a;

		//find out the size of binary file
		std::filesystem::path filepath = a;
		auto b = std::filesystem::file_size(filepath);
		std::cout <<  b << "\n";
		
		//infile.open(a ,std::ios::binary|std::ios::in);
		
	}
