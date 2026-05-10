#include "complex.h"

// Interface functions
complex_t *getComplexNumber(real_t x, img_t y)
{
    complex_t *newComplexNumber = NULL;

    newComplexNumber = (complex_t *)xmalloc(sizeof(complex_t));
    newComplexNumber->re = x;
    newComplexNumber->im = y;

    return (newComplexNumber);
}
void releaseComplexNumber(complex_t **ppComplex)
{
    complex_t *complexNumber = NULL;

    complexNumber = *ppComplex;
    free(complexNumber);
    complexNumber = NULL;
    *ppComplex = NULL;
}

complex_t *add(complex_t *pC1, complex_t *pC2)
{
    return(getComplexNumber(pC1->re + pC2->re,pC1->im+pC2->im )); 
}
complex_t *sub(complex_t *pC1, complex_t *pC2)
{
    return(getComplexNumber(pC1->re - pC2->re,pC1->im - pC2->im )); 

}
complex_t *mult(complex_t *pC1, complex_t *pC2)
{
    return(getComplexNumber(pC1->re *pC2->re-pC1->im * pC2->im,pC1->re *pC2->re+pC1->im * pC2->im )); 

}
complex_t *cpa_div(complex_t *pC1, complex_t *pC2)
{
    real_t divReal;
    img_t divImg;

    divReal = (pC1->re*pC2->re + pC1->im*pC2->im)/(pC2->re*pC2->re + pC2->im*pC2->im);
    divImg = (pC1->im*pC2->re -pC1->im*pC2->im) / (pC2->re*pC2->re + pC2->im*pC2->im);

    return (getComplexNumber(divReal,divImg));
}

void show(complex_t *pC, const char *msg)
{
    if (msg)
        puts(msg);

    printf("(%.3lf)+i(%.3lf)\n", pC->re, pC->im);
}

// Helper function
void *xmalloc(size_t size)
{
    void *ptr = NULL;
    ptr = malloc(size);
    if (NULL == ptr)
    {
        puts("malloc():fatal:out of memory");
        exit(EXIT_FAILURE);
    }
    return (ptr);
}