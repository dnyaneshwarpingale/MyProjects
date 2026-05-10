#include <stdio.h>
#include <stdlib.h>

struct A{
    int num1, num2;
    short n1, n2, n3, n4;
    unsigned long long int arr[4];
}inA = {
    0x11223344,
    0x55667788,
    0xaaaa, 0xbbbb, 0xcccc, 0xdddd,
    0x0102030405060708,
    0x1020304050607080,
    0x0a0b0c0daabbccdd,
    0xa0b0c0d0aabbccdd

};

struct B{
    int a[5];
    short p, q , r, s;
};

void printA(struct A* pA, const char* msg);

int main(void)
{
    printA(&inA, "Before Type casting:");
    ((struct B*)&inA)->p = 0xFFFF;
    printA(&inA, "After Type casting");

    return 0;
}

void printA(struct A* pA, const char* msg)
{
    if(msg)
        puts(msg);

    puts("Printing int num1, num2");
    printf("pA->num1 = %x, pA->num2 = %x\n", pA->num1, pA->num2);
    puts("Printing Shorts n1, n2, n3, n4:");
    printf("pA->n1 = %hx, pA->n2 = %hx, pA->n3 = %hx, pA->n4: %hx\n", pA->n1, pA->n2, pA->n3, pA->n4);

    puts("Printing  array of unsigned long long ints");
    for (size_t i = 0; i < 4;++i)
        printf("pA->[%llu]: %llx\n", i, pA->arr[i]);
}