/*Pan Vladimir st128934@student.spbu.ru
  modified hello world
*/

#include <iostream>
#include <string>


void print(std::string word){
	std::cout << "Hello, " << word << "\n";
	std::cin >> word;
	print(word);
}

	