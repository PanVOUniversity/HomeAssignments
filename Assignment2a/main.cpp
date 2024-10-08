/*Pan Vladimir st128934@student.spbu.ru
  naive reverce of binary file
*/

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>

int main()
	{
		//input path
		std::string a;
		std::cout << "input path, pls \n";
		std::cin >> a;
		
		//find out the size of binary file
		std::filesystem::path filepath = a;
		auto b = std::filesystem::file_size(filepath);
		std::cout <<  b << "\n";
		std::ifstream infile;
		infile.open(a ,std::ios::binary|std::ios::in);
		
		//open file, write it into the array, close it, delete it
		infile.open(a ,std::ios::binary|std::ios::in);
		char buffer [b];
		if (infile.is_open())
		{
			infile.read((char *)&buffer,sizeof(buffer));
			infile.close();
			
		}	
		
		//naive reverse realisation
		int buffersize = sizeof(buffer)/sizeof(buffer[0]);
		for (int i = 0;i < buffersize; i++)
		{
			std::swap(buffer[i], buffer[buffersize - i]);
			
		}
		
	       //writing array in new file

		std::ofstream("reversed.txt") << buffer;			 
	}
