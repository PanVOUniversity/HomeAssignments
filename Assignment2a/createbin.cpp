#include <iostream>
#include <fstream>
#include <string>
std::ifstream infile;

int main()
        {
                std::string a = "My information in bin file";
                std::ofstream fout("mybin.bin", std::ios_base::binary); //create class ofstream object 
 		fout.write((char*)&a, sizeof(int));
		fout.close();
		return 0;

        }

