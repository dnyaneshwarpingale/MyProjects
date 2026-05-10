#include <stdio.h>
#include <stdlib.h>

typedef enum base
{
    OCTAL = 1,
    DECIMAL,
    HEXADECIMAL,
} base_t;

struct Date
{
    int day;
    int month;
    int year;
};

void byte_dump(void* ptr, size_t N, base_t base, const  char* desc);

int main(void)
{
    char* cpa_name = "CORECODE PROGRAMMING ACADEMY";
    struct Date dateInstance =  {7, 2, 2026};
    unsigned int permission_byte = 0777;

    byte_dump((void*)cpa_name, strlen(cpa_name), DECIMAL, "Academy name:");
    byte_dump((void*)&dateInstance, sizeof(struct Date), HEXADECIMAL, "Date:");
    byte_dump((void*)&permission_byte, sizeof(unsigned int), OCTAL, "Permission");

    return (0);
}

void byte_dump(void* ptr, size_t N, base_t base, const char* desc)
{
    static const char* fmt_dec = "BYTE[%llu]:%hhd\n";
    static const char* fmt_octal = "BYTE[%llu]:%hho\n";
    static const char* fmt_hex = "BYTE[%llu]:hhx\n";
    static const char* current_fmt = NULL;

    if(ptr == NULL)
        return;
    if(desc)
        puts(desc);
    

    switch(base)
    {
        case OCTAL:
            current_fmt = fmt_octal;
            break;
        case DECIMAL:
            current_fmt = fmt_dec;
            break;

        case HEXADECIMAL:
            current_fmt = fmt_hex;
            break;
        default:
            current_fmt = fmt_dec;
            break;
    }

    for(size_t i = 0; i < N; ++i)
        printf(current_fmt,i, *(unsigned char*)((char*)ptr +i));
}
