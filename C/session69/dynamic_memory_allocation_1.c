#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    /* step 1: Define a pointer variable and initialize to NULL */
    int* p = NULL;  
    int n; 

    /* 
        step 2: Call malloc() which is a dynamic memory allocation function 
        to allocate memory to an integer and capture the address returned 
        by malloc() in the pointer 
    */
    p = (int*)malloc(sizeof(int)); 

    /* 
        step 3: You must *ALWAYS* (WITHOUT FAIL) check whether call to 
        dynamic memory allocation has succeeded or not. 
    */
    if(p == NULL)
    {
        puts("fatal:error in allocating memory"); 
        exit(-1); 
    }

    /*  
        step 4/5: use dynamically allocated integer through pointer 
        use means perform read / write operations 
    */
    *p = 500;
    n = *p; 

    printf("n = %d\n", n); 
    printf("*p = %d\n", *p); 

    /* 
        step 6: Whenever you want deallocate the memory allocated by malloc() 
        using a free function 
    */
    free(p);
    p = NULL;   /* Step 7: reset pointer to NULL */ 

    return (0); 
}
