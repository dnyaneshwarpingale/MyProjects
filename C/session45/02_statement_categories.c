/* 
Statements in C programming language can be broadly divided into two 
categories: 

1) Data Definition Statement: Statements which are responsible for allocating 
memory are known as the data definition statements. 
e.g. 
int a = 10; 
int c = 300; 
float f_num = 3.14; 

Data definition statements can be written OUTSIDE ALL functions or 
INSIDE any function. 

e.g. consider test.c file 

test.c 

int a = 10; 

int main(void)
{
    float f_num = 3.14; 
}

Line #18 and Line #22 are data definition statements. 
Data definition statement on Line #18 is written outside all functions. 
Data definition statement on line #22 is written inside the main() function. 

2) Data Manipulation Statements: Statements which are responsible for processing 
allocated data are known as DATA MANIPULATION STATEMENTS. 

e.g. 
assignment statement 
num_1 = 100; 
num_2 = 200; 
sum = num_1 + num_2; 

if(num > 0)
{
    printf("num is positive\n"); 
}

RULE: ALL DATA MANIPULATION STATEMENTS MUST BE INSIDE A FUNCTION. 
Let test.c be a source file. 

test.c 

int num_1 = 100;    // data definition statement 
int num_2 = 200;    // data definition statement 
int sum;            // data definition statement 
sum = num_1 + num_2; // ERROR. data manipulation statement must be 
                     // inside a function 

// ERROR -> if is a data manipulation statement 
// call to puts() is a data manipulation statement 
// therefore, these must be written inside some function 
// they cannot appear outside all functions. 
if(sum > 0)
{
    puts("Summmation is positive"); 
}

int main(void)
{
    sum = num_1 + num_2;    // data manipulation statement 

    // if statement -> data manipulation statement 
    // call to puts() function -> data manipulation statement 
    // both of these statements cannot be written outside the 
    // function 
    if(sum > 0)
    {
        puts("Summmation is positive"); 
    }
}

*/