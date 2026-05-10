int printf(const char* fmt, ...); 

char chr = 'A'; 
unsigned char b_num = 145; 
short s_num = -1582; 
unsigned short us_num = 58200; 
int n = 348761; 
unsigned int un = 346346; 
long int lng_n = -36343632; 
unsigned long int u_lng_n = 383045; 
long long int v_lng_n = -3623536256236362; 
unsigned long long u_v_lng_n = 6252562525; 
float f_num = 3.14; 
double d_num = 346346.4625; 

int main(void){
    printf("chr = %c\n", chr); 
    printf("b_num = %hhu\n", b_num);
    printf("s_num = %hd\n", s_num); 
    printf("us_num = %hu\n", us_num); 
    printf("n = %d\n", n); 
    printf("un = %u\n", un); 
    printf("lng_n = %ld\n", lng_n); 
    printf("u_lng_n = %lu\n", u_lng_n); 
    printf("v_lng_n = %lld\n", v_lng_n);
    printf("u_v_lng_n = %llu\n", u_v_lng_n);  
    printf("f_num = %.2f\n", f_num); 
    printf("d_num = %.4lf\n", d_num); 
    printf("s_num = %hd, n = %d\n", s_num, n); 
    printf("chr=%c, b_num=%hhu, s_num=%hd, us_num=%hu, n=%d, un=%u, lng_n=%ld, u_lng_n=%lu, v_lng_n=%lld, u_v_lng_n=%llu, f_num=%.2f, d_num=%.4lf\n", 
    chr, b_num, s_num, us_num, n, un, lng_n, u_lng_n, v_lng_n, u_v_lng_n, f_num, d_num); 
    
    printf("BACKWARD SLASH = \\t \n");
    return (0);
}

// %f   DEFAULT PRECISION LEVEL 6. CUSTOM PRECISION LEVEL: %.nf 
// %lf  DEFAULT PRECISION LEVEL 6. CUSTOM PRECISION LEVEL: %.nlf 
