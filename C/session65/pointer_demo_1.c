#include <stdio.h> 

void test_func(void); 

int main(void)
{
    test_func(); 
    return (0);     
}

void test_func(void)
{
    int n = 10; 
    int* ptr; 

    ptr = &n; 

    printf("1)n = %d\n", n); 
    *ptr = 20; 
    printf("2)n = %d\n", n); 
}

// instance 
// instantiation = to make an instance of 
// नग = instance 

// start reading the C definition from its name 
// then determine the entity of which the variable name is an instance 
// possible entities : 
// 1) instance of built in data type 
// 2) instance of a structure
// 3) instance of an array
// 4) instance of a function 
// 5) instance of a pointer 

// 1) Entity is a built in data type : built_in_type_name var_name; 
// char c; 
// int n; 
// float f; 

// 2) Entity is a struture : struct_name var_name; 
// struct Date myDate; 
// struct Book bk; 

// 3) Entity is an array: element_type var_name[optional_size]; 
// int arr[5]; 
// int a[] = {100, 200, 300, 400}; 
// float f_arr[8]; 
// char msg[32]; 

// 4) Entity is a function type: return_value_type function_name(formal_parameter_list); 
// int main(void); 
// void sort(int [], int ); 

// 5) Entity is a pointer type: type_name* var_name; 

// builtin/structure:   v
// array:               v[]
// function:            v()
// pointer:             *v
