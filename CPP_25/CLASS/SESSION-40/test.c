#include <stdio.h>

void test()
{
    int* p = NULL;
    int num;

    num = 100;

    char* s = "Hello";
}

/*
    num = 100;
    movl $100, num

    MOV-OPCODE 100  numaddr

    [PREFIX] [OPCODE] [MOD R/M] [SIB] [IMMEDIATE] [DISPLACEMENT]
    1BYTE     1-3byte 1 byte     1 byte 4 byte    4 byte
*/

int num;

void test()
{
    num = 100;
}