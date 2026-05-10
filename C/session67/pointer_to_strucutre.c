#include <stdio.h> 

struct Test
{
    int i_num; 
    char c; 
    float f_num; 
}; 

void test(void); 

int main(void)
{
    struct Test inT; 
    struct Test* pTest; 

    inT.i_num = 100; 
    inT.c = 'A'; 
    inT.f_num = 3.14; 

    pTest = &inT; 

    printf("value of i_num in inT = %d\n", pTest->i_num); 
    printf("value of c in inT = %c\n", pTest->c); 
    printf("value of f_num in inT = %.2f\n", pTest->f_num); 

    test(); 
    return (0); 
}

void test(void)
{
    puts("Inside test function"); 
    struct Test var_1 = {100, 'A', 1.1}; 
    struct Test var_2 = {200, 'B', 2.2}; 

    struct Test* pTest; 

    pTest = &var_1; 

    printf("%d\n", pTest->i_num); /* 100 */

    pTest = &var_2; 

    printf("%d\n", pTest->i_num); /* 200 */
}

/* 
-> is a BINARY INFIX OPERATOR 

OPERAND_1->OPERAND_2

OPERAND_1 MUST BE A POINTER TO STRUCTURE 
OPERAND_2 MUST BE A MEMBER NAME IN STRUCTURE OF WHICH OPERAND_1 IS A POINTER

struct Date{}; 

struct Book{}; 

struct Umbrella{}; 

struct Test{}; 

struct Date* p1; 
struct Book* p2; 
struct Umbreall* p3; 
struct Test* p4; 

p1->    CHALEL 
p2->    CHALEL
p3->    CHALEL 
p4->    CHALEL 

pointer to structure: 

lhs->rhs 


*/

/* 
    type(inT) == struct Test ...given by programmer 

    type(inT.i_num) == int  ... given by programmer 

    type(&inT.i_num) == int* 

    therefore 

    v = &inT.i_num 

    type(v) must be int* 

    int* v; 

    v = &inT.i_num; 
    iS CORRECT
*/