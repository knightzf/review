#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    int a = atoi(argv[1]);
    for(int i = 0; i < 32; ++i)
    {
        if(a&(0x01<<i))
            std::cout<<i<<std::endl;
    }
}
