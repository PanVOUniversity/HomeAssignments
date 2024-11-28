#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include "bmp.h"


void test()
{
    
    std::string path = "lena_gray.raw";
    Image image = Image(512, 512, path);
    std::vector<unsigned char> vector = image.readToVector(path, 512*512);
    /*
    for(int i = 0; i<= 10; i++)
    {
        std::cout<<vector[i]<<std::endl;
    }
    */
    image.writeToFile("new.bmp",vector);
    image.writeToRaw("new.raw", vector);
    image.writeToRaw("cwrotated.raw",image.clockwiseRotate(vector));
    image.writeToRaw("ccwrotated.raw", image.counterClockwiseRotate(vector));
}

int main()
{
    test();
}