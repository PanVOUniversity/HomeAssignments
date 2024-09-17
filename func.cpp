/*Pan Vladimir st128934@student.spbu.ru
  modified hello world
*/

#include <iostream>
#include <string>


void print(std::string word){
	cout << word;
	cin >> word;
	print(word);
}

	
