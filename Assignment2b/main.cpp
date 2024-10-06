#include <iostream>

int main()
	{
		char* stack = new char [100];
		const char* operations[4] = {"+","-","*","/"};
		
		while (true)
		{
			
			char s;
			std::cin >> s;
			stack += 1;
			for (int i=0; i<4; i++)
			{
				if (*operations[i] == s)
				{
					int sum = 0;
					do
					{
						if (i=0)
						{ 
							sum += *stack - 0;
						}
						else if (i = 1)
						{
							sum -= *stack - 0;
						}
						else if (i = 2)
						{
							sum *= *stack - 0;
						}
						else if (i = 3)
						{
							sum /= *stack - 0;
						}
					}
					while(*stack != stack[-1]);
	
					delete stack;
					char* stack = new char [100];
					std::cout << stack[0];
				}
			}
		}
	}	
