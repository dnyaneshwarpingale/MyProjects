#include "complex.h"

int main(void)
{
    complex_t *pC1 = getComplexNumber(1.1, 2.2);
    complex_t *pC2 = getComplexNumber(3.3, 5.5);

    show(pC1, "pC1:");
    show(pC2, "pC2:");

    complex_t *addition = add(pC1, pC2);
    complex_t *substraction = sub(pC1, pC2);
    complex_t *multiplication = mult(pC1, pC2);
    complex_t *division = cpa_div(pC1, pC2);

    show(addition, "Addtion:");
    show(substraction, "Substraction:");
    show(multiplication, "Multiplication:");
    show(division, "Division:");

    releaseComplexNumber(&addition);
    releaseComplexNumber(&substraction);
    releaseComplexNumber(&multiplication);
    releaseComplexNumber(&division);
    releaseComplexNumber(&pC1);
    releaseComplexNumber(&pC2);

    complex_t* i = getComplexNumber(0.0,1.0);
    complex_t * i_x_i = mult(i,i);
    show(i,"i:");
    show(i_x_i,"i2:");

    releaseComplexNumber(&i);
    releaseComplexNumber(&i_x_i);

    return (0);
}