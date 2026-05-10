#include <stdio.h> 

int main(void)
{
    int n = 10; 
    int* ptr; 
    ptr = &n; 

    int m; 

    printf("Address of n:%p\n", &n); 
    printf("address of variable n:%llu\n", (unsigned long long)&n); 
    printf("address of variable ptr:%llu\n", (unsigned long long)&ptr); 
    printf("address in variable ptr:%llu\n", (unsigned long long)ptr); 

    m = 0; 
    printf("m = %d\n", m); 
    m = *ptr; // m should be 10 
    printf("m = %d\n", m); 

    printf("n = %d\n", n); 
    *ptr = 20;  // n should be 20 
    printf("n = %d\n", n); 

    return (0); 
}
