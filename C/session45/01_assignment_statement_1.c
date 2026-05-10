/* 
    Assignment statement: 
    General Syntax: 
    LHS = RHS; 
    LHS -> left hand side 
    RHS -> right hand side 
    =   -> assignment operator 

    READ: 
    RHS IS ASSIGNED TO LHS 
    NOT 
    LHS is EQUAL TO RHS 

    e.g. 
    a = 10; 
    LHS -> a 
    RHS -> 10 
    = -> assignment operator 

    READ 
    10 is ASSIGNED TO 'a' 
    NOT 
    a is equal to 10 

    ASSIGNMENT OPERATOR IS USED TO SET VALUES IN MEMORY LOCATION. 
    THE LEFT HAND SIDE OF THE ASSIGNMENT OPERATOR SHOULD BE MEMORY LOCATION 
    WHOSE VALUE IS TO BE SET NOW. ONE OF THE WAYS THE MEMORY LOCATION IS EXPRESSED 
    BY NAME GIVEN TO IT (i.e. VARIABLE)

    int a; // four bytes are allocated in program memory 

    If I wish to put value 3892 in those four bytes, I can use the assignment statement. 
    Four bytes that are allocated in memory are named as 'a'. 
    Therefore variable 'a' must be the LHS. 
    And 3892 is a value that must be put in those four bytes. Therefore, it must be on the RHS 

    a = 3892; 

    3892 is assigned to 'a'

    int num1; 
    int num2; 
    int sum; 

    int main(void)
    {
        num1 = 100; 
        num2 = 200; 
        sum = num1 + num2; 

        num1 = 100; 
        100 = num1; 
    }

*/

int main(void)
{
    int num1; 

    100 = num1; /*  
                    lvalue is missing. 
                    lvalue -> location value 
                    -> starting address of a memory location 
                    where RHS value will be stored  
                */
}