#include <stdio.h>
#include <stdlib.h>

struct A
{
    int a;
    char b;
    float c;
};

void print_all_members_1(float * pC);
void print_all_members_2(float* pC);

int main(void)
{
    struct A X =  {10, 'A', 1.1f};
    struct A Y = { 20, 'B', 2.2f};
    struct A Z = {30, 'C', 3.3f};

    print_all_members_1(&X.c);
    print_all_members_1(&Y.c);
    print_all_members_1(&Z.c);

    print_all_members_2(&X.c);
    print_all_members_2(&Y.c);
    print_all_members_2(&Z.c);

    return (EXIT_SUCCESS);
    
}

void print_all_members_1(float* pC)
{
    struct A* p_base = ((struct A*)(unsigned long long )pC - (unsigned long long int)(&((struct A*)0)->c));

    printf("p_base->a =%d, p_base->b = %c, p_base->c = %.1f\n", p_base->a, p_base->a, p_base->b, p_base->c);

}

void print_all_members_2(float* pC)
{
    #define OFFSET_OF(T, mem) ((unsigned long long int)(&((T*)0)->mem))
    #define CONTAINER_OF(addr, T, mem) ((T*)((unsigned long long int)addr - OFFSET_OF(T,mem)))

    struct A* p_base = CONTAINER_OF(pC, struct A, c);
    printf("Macro Edition:p_base->a  = %d , p_base->b = %c, p_base->c = %.1f\n", p_base->a, p_base->b, p_base->c);

}



















