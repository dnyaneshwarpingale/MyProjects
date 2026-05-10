#include <stdio.h>
#include <stdlib.h>

struct A
{
    int a;
    char b;
    float c;
};

void calculate_1(void);
void calculate_2(void);
void calculate_3(void);
void calculate_4(void);

int main(void)
{
    calculate_1();
    calculate_2();
    calculate_3();
    calculate_4();
    return (EXIT_SUCCESS);
}

void calculate_1(void)
{
    struct A x;
    unsigned long long int offset_a , offset_b, offset_c;
    offset_a = (unsigned long long int )&x.a - (unsigned long long int)&x;
    offset_b = (unsigned long long int )&x.b - (unsigned long long int)&x;
    offset_c = (unsigned long long int )&x.c - (unsigned long long int)&x;

    printf("offset_a = %llu, offset_b = %llu, offset_c = %llu\n", offset_a, offset_b, offset_c);
    
}

void calculate_2(void)
{
    struct  A* pA = NULL;
    unsigned long long int offset_a, offset_b, offset_c;

    offset_a = (unsigned long long int)&pA->a;
    offset_b = (unsigned long long int)&pA->b;
    offset_c = (unsigned long long int)&pA->c;
    printf("offset_a = %llu, offset_b = %llu, offset_c = %llu\n", offset_a, offset_b, offset_c);

}

void calculate_3(void)
{
    unsigned long long int offset_a = (unsigned long long int )(&((struct A*)0)->a);
    unsigned long long int offset_b = (unsigned long long int )(&((struct A*)0)->b);
    unsigned long long int offset_c = (unsigned long long int )(&((struct A*)0)->c);

    printf("offset_a = %llu, offset_b = %llu, offset_c = %llu\n", offset_a, offset_b, offset_c);


}

void calculate_4()
{
    #define OFFSET_OF(T, mem)  ((unsigned long long int)(&((T*)0)->mem))
    
    printf("Offset_of(Struct A, a) = %llu\n", OFFSET_OF(struct A, a));
    printf("Offset_of(Struct A, b) = %llu\n", OFFSET_OF(struct A, b));
    printf("Offset_of(Struct A, c) = %llu\n", OFFSET_OF(struct A, c));
}