void* malloc(size_t); 

typedef unsigned long long int size_t; 

typedef int int_t; 

typedef int INT; 

int num; 
int_t num; 
INT num; 

unsigned long long int n; 
size_t n; 

malloc(16); 

4 integers array 
8 short array 
2 unsigned long long 
struct Test -> sizeof(struct Test) 

int n; 
type(n) == int 
type(&n) == int* 

float f; 
type(&f) == float* 

struct Date myDate; 

type(myDate) == struct Date 
type(&myDate) == struct Date* 


sizeof(int) == 4 
sizeof(float) == 4 

int* malloc(size_t size);

float* malloc(size_t size); 

void* malloc(size_t); 