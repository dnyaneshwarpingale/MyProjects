int printf(const char* fmt, ...); 

char chr = 'A'; 
int n = 100; 
float f_num = 3.14; 

int main(void){
    printf("Address of chr = %p\n", &chr);
    printf("Address of n = %p\n", &n); 
    printf("Address of f_num = %p\n", &f_num); 
    return (0); 
}

// address of chr == address of a byte whose name is chr 
// address of n == address of a byte whose name is n 
// address of f_num == address of a byte whose name is f_num 

// int n = 10; 