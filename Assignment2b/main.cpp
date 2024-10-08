#include <iostream>

int main()
	{
		char *stack = new char [100];
		const char* operations[4] = {"+","-","*","/"};
		char s;
		//for debug
		char a;
		std::cout << **operations;
		//---------------
		while (true)
		{
			std::cin >> s;
			
			//checking if the operator has been inputed
			for (int i=0; i<4; i++)
			{
				if (operations[i][0] == s)
				{
					int sum = 0;
					
					//when operator has been defined
					//back iterate massive
					if (i=0)
					{ 	
						std::cout << "in 2st if"; //debug
						while (*stack != NULL)
						{
							std::cout << "in while" << stack; //debug
							sum += *stack - 0;
							std::cin >> a;
							--stack;	
						}
					}
					else if (i == 1)
					{
						while (*stack != NULL)
						{
							sum -= *stack - 0;
							--stack;	
						}
					}
					else if (i == 2)
					{
						while (*stack != NULL)
						{
							sum *= *stack - 0;
							--stack;
						}
					}
					else if (i == 3)
					{
						while (*stack != NULL)
						{
							sum /= *stack - 0;
							--stack;	
						}
					}
					
					delete[] stack;
					char* stack = new char [100];
					
				}
			
			}

			// adding new element in array
			*stack = s;
			//going to next element
			std::cout << *stack <<std::endl;
			++ stack; 
			std::cout << stack;
			//for int i = 0, i < si
		}	
		

	}	
