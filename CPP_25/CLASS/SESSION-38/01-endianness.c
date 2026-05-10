#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0x0A0B0C0D;

    if(*(unsigned char*)&n == 0xD)
        puts("Little Endian");
    else if (*(unsigned char*)&n == 0xA)
        puts("Big Endian");
    else
        puts("control will nevever reach here");

    return (0);
}

/*
    type(&n) == int*
    type((unsigned char*)&n) == unsigned char*

    Meaning of * operator will be applied in the context of unsigned char
    
*/