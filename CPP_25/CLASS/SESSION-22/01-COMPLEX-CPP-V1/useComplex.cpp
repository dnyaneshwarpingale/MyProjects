#include "complex.hpp"
void test_complex(void);

int main(void)
{
    test_complex();
    return (EXIT_SUCCESS);
}

void test_complex(void)
{
    complex c1(1.1,2.2);
    complex c2(3.3,4.4);

    complex c_add = c1.add(c2);
    complex c_sub = c1.sub(c2);
    complex c_mult = c1.mult(c2);
    complex c_div = c1.div(c2);

    c1.show("c1: ");
    c2.show("c2: ");

    c_add.show("c_add: ");
    c_sub.show("c_sub: ");
    c_mult.show("c_mult: ");
    c_div.show("c_div: ");
}