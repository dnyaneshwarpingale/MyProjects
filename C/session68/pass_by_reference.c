#include <stdio.h> 

void test_function(int*); 

int main(void)
{
    int n = 100; 

    printf("main:address of (n) = %llu\n", (unsigned long long)&n); 
    printf("main:BEFORE:value of (n) = %d\n", n); // 100 

    test_function(&n); 

    printf("main:AFTER:value of (n) = %d\n", n); // 500

    return (0); 
}

void test_function(int* ptr)
{
    printf("test_function:address in ptr = %llu\n", (unsigned long long)ptr); 
    printf("value in integer whose address is in ptr:%d\n", *ptr); 
    *ptr = 500; // CONTENTS of ptr (address of integer block sent by caller)
                // are treated as address and 500 is written on those addresses 
                // in short 'AN INTEGER WHOSE ADDRESS IS SENT BY THE CALLER 
                // AS ACTUAL PARAMTER WILL UNDERGO CHANGE' 
                // not the pointer WHICH IS A FORMAL PARAMETER 
}