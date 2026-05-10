int printf(const char* fmt, ...); 

int main(void){
    int c; 

    c = 2000; 
    while(c < 3000)
    {
        printf(" %hhu = %c\n", c, c); 
        c = c + 1; 
    }

    return (0); 
}

