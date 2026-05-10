#include <stdio.h> 

// big_num: 
// x    x+1     x+2     x+3     x+4     x+5     x+6     x+7 
// 88   77      66      55      44      33      22      11   as per little endian 
// 11   22      33      44      55      66      77      88   as per big endian 

unsigned long long big_num = 0x1122334455667788; 
int* ptr = NULL; 
int n = 0xaabbccdd; 

int main(void){
    printf("n = %x\n", n); //   0xaabbccdd 
    ptr = &n; 
    *ptr = big_num; 
    printf("n = %x\n", n); // 0x55667788 

    return (0); 
}


