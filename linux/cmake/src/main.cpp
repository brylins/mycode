#include <stdio.h>
#include "../include/add.hpp"

int main(int argc, char** argv)
{
    int a = 1; 
    int b = 2;

    printf("a=%d b=%d\n", a, b);
    add(a, b);
    printf("a+b=%d\n",a+b);
	
    return 0;
}