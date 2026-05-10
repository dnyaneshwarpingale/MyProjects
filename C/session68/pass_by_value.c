#include <stdio.h> 

void test_function(int); 

int main(void)
{
    int n = 100; 

    printf("BEFORE calling test_function:n:%d\n", n);
    test_function(n); 
    printf("AFTER calling test_function:n:%d\n", n); 
    
    return (0);  
}

void test_function(int m)
{
    printf("inside test_function:m:%d\n", m); 
    m = 500; 
    printf("inside test_function:m:%d\n", m); 
}

