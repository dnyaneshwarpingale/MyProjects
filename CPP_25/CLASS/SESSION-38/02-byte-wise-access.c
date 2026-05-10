#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    unsigned long long x = 0;

    printf("x = %llx\n", x);

    *((unsigned char *)&x) = 0xff;

    printf("x = %llx\n", x);

    *((unsigned short *)((char *)&x + 1)) = 0xffff;
    printf("x = %llx\n", x);

    *((unsigned int *)((char *)&x + 3)) = 0xffffffff;
    printf("x = %llx\n", x);
    *((unsigned char *)((char *)&x + 7)) = 0xff;

    printf("x = %llx\n", x);

    return (0);
}
