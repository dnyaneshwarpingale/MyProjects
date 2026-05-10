#include <stdio.h>      /* for declaration of printf(), puts(), scanf() */
#include <stdlib.h>     /* For declaration of exit() */
#include <math.h>       /* for declaration of sqrt()  */

int main(void)
{
    double a;   /*  For storing Co-efficient of x^2 */
    double b;   /*  For storing Co-efficient of x */
    double c;   /*  For storing constant */
    double root_1; /* For storing the value of root 1 */
    double root_2; /* For storing the value of root 2 */
    double delta; 

    printf("Enter the CF of x^2:"); 
    scanf("%lf", &a); 

    if(a == 0.0)
    {
        puts("CF of x^2 cannot be zero in the quadratic equation"); 
        exit(-1); 
    }

    printf("Enter the CF of x:"); 
    scanf("%lf", &b); 

    printf("Enter the constant:"); 
    scanf("%lf", &c); 

    if((b*b - 4*a*c) < 0.0)
    {
        puts("This quadratic equation does not have real roots"); 
        exit(-1); 
    }    

    delta = sqrt(b*b-4*a*c); 
    root_1 = (-b + delta)/(2*a); 
    root_2 = (-b - delta)/(2*a); 

    printf("root_1:%.3lf, root_2:%.3lf\n", root_1, root_2); 
    return (0); 
}

