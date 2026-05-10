 #include <stdio.h>
#include <stdlib.h>

/*
  Pointer : int * p=NULL; variable p is pointer

   int num_1;

   p=&num_1; //variable p is a pointer, num_1 is pointee
            // because address of variable num_1 is stored in p

   p= (int*)malloc(sizeof(int));

   //variable p is pointer
   //integer variable allocated on heap section by malloc() function
   //is a pointee because its address is returned by malloc() and 
   // stored pointer p.
*/

void pointr_to_const_demo(void);
void const_pointer_demo(void);
void const_pointer_to_pointer_to_const_demo(void);

int main(void)
{
    pointer_to_const_demo();
    const_pointer_demo();
    const_pointer_to_pointer_to_const_demo();

    return (0);
}

void pointer_to_const_demo(void)
{
  int num = 10; // local data definition statement
                // allocats local integer on the stack frame
  
 const int* p = &num; //local data definition statement
                        // allocates pointer p on the stack frame
                        // stores the address of local integer
                        // which is allocated on the same stack frame

// Declaration reading: p is a pointer to const int
// in this syntax, the pointer variable itself is not  constant
// meaning that we ca reassign p to point to some other integer than num

// But pointee is treated as const. Therefore , it is not allowed 
// to use expression  'p on LHS. If we do so, we will be greeeted wih the 
// following  error,
// *p =500;   // CTE : LHS Must a Modifiable lvalue

printf("num = %d\n", num); //10
num =500;
printf("num =%d\n", num); //500



}

void const_pointer_demo(void)
{

}

void const_pointer_to_pointer_to_const_demo(void)
{

}