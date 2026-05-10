#include <stdio.h>

extern int global_num;
extern void test_function(void);

//extern static int s_num;                // compile time error
                                            // extern and static qualifiers cannot be applied together

//extern static vvoid test_function_2(void); //compile time error 
                                              // extern and static qualifiers cannot be applied together
                                              
int main(void)
{
    printf("Entered main() function implemented in file %s\n", __FILE__);
    printf("main():initial state of global_num =%d\n", global_num);

    //changing state of global_num to 1000

    //this function prints global_num and s_num
    //Expectation : global_num will reflect its changed state 100
    //test_function() calls test_function_2() inside it.
    //therefore, expect printfs() from test_function_2() as well
    test_function();

    return (0);
}

// Inference: In C, global data or global functions are not only visible in all functions in a source file
// in which they are defined, but also  are visible in all functions in all fies in that project.
// global scope == project wide global scope
//Of course we need extern keyword for declaring their types in other source file.

//Between global scope (== project wide global scope) and local scope (== stipulated to a function), there 
//is another level of visibility, global to source file or translation unit wherein a data or function 
// variable is visible to all functions in source file wherein they are defined but not in other source files 
// or translation units in that project.