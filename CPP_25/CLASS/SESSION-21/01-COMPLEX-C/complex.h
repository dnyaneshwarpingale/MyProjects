#ifndef _COMPLEX_H
#define _COMPLEX_H
#include<stdio.h>
#include<stdlib.h>

typedef double real_t;
typedef double img_t;
typedef struct complex complex_t;

struct complex
{
    real_t re;
    img_t im;
};

// Interface functions
complex_t *getComplexNumber(real_t x, img_t y);
void releaseComplexNumber(complex_t **ppComplex);

complex_t *add(complex_t *pC1, complex_t *pC2);
complex_t *sub(complex_t *pC1, complex_t *pC2);
complex_t *mult(complex_t *pC1, complex_t *pC2);
complex_t *cpa_div(complex_t *pC1, complex_t *pC2);

void show(complex_t *pC, const char *msg);

// Helper function
void *xmalloc(size_t size);  

#endif