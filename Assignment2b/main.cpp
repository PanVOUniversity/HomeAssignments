#include <iostream>

int main()
	{
		char array [100];
		char& stack = array[0];
		const char* operations[4] = {"+","-","*","/"};
		
		while (true)
		{
			
			char s;
			std::cin >> s;
			stack += sizeof(array)/sizeof(array[0]);
			for (int i=0; i<4; i++)
			{
				if (*operations[i] == s)
				{
					int sum;
					for (int j = 0; j < sizeof(stack)/ sizeof(stack);++j)
					{
						if (i=0)
						{ 
							sum += *stack[j] - 0;
						}
						else if (i = 1)
						{
							sum -= stack[j] - 0;
						}
						else if (i = 2)
						{
							sum *= stack[j] - 0;
						}
						else if (i = 3)
						{
							sum /= stack[j] - 0;
						}
					
					}
					delete stack;
					char& stack = array[0];
					std::cout << array[0];

				}
			
				else
			}
		
					
			
										
							break;
	}	
