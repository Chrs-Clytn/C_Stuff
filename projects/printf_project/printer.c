#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void my_reverse(char str[], int len)
{
    int start, end;
    char temp;
    for(start=0, end=len-1; start < end; start++, end--) {
        temp = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = temp;
    }
}

char* my_itoa_base(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
    if (num == 0) {
        str[i] = '0';
        str[i + 1] = '\0';
        return str;
    }
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }  
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if (isNegative){
        str[i++] = '-';
    }
    str[i] = '\0';
    my_reverse(str, i);
    return str;
}

int my_printf(const char* input, ...)
{
    va_list arg; 
    va_start(arg, input); 
    const char* value;
    char* s;
    char charArray[10];
    signed int i;
    int p_value;
    int count = 0;

    for (value = input; *value; value++)
    {
        if(*value != '\0')
        {
            if (*value != '%')
            {
            putchar(*value);
            count++;
            continue;
             }
        switch (*++value)
        {
            case 'c':
                i = va_arg(arg, int);
                putchar(i);
                count++;
                continue;

            case 'd':
                i = va_arg(arg, int);
                char *my_string = my_itoa_base(i, charArray, 10);
       
                for (int i = 0; i < (int) strlen(my_string); i++)
                {
                    putchar(my_string[i]);
                    count++;
                }
                continue;

            case 'o' :
                i = va_arg(arg, int);
                char *my_hex_string = my_itoa_base(i, charArray, 8);

                for (int i = 0; i < (int) strlen(my_hex_string); i++)
                {
                    putchar(my_hex_string[i]);
                    count++;
                }
                continue;

            case 's':
                s = va_arg(arg, char*);
                if (s == NULL)
                {                 
                    char* null_s = "(null)";
                    int length = strlen(null_s);

                    write(1, null_s, (length + 1));
                    count = count + length;
                }

                else
                {
                    int length = strlen(s);
                    write(1, s, (length + 1));
                    count = count + length;
                }
                continue;
            case 'p':

                p_value = va_arg(arg, int);
                intptr_t number = (intptr_t)p_value; 
                char buffer[2 + sizeof(number) * 2]; 
                int index = 0;
                int size_buffer_to_fill = sizeof(buffer) - 2; 
                buffer[0] = '0';
                buffer[1] = 'x';                
                for (index = 0; index < size_buffer_to_fill; index++)
                {
                    buffer[index + 2] = "0123456789abcdef"[(number >> ((size_buffer_to_fill - 5 - index) * 4)) & 0xf]; // Shift 5 digits to offset for leading zeros in original address
                }
                
                write(1, buffer, sizeof(buffer) - 4);
                count = count + sizeof(buffer) - 4;
                continue;

            default:
                putchar(*value);
                count++;
                continue;
        }   
        }
    }
    va_end(arg);
    return count;
}

int main()
{
 /*   assert(13 == my_printf("Hello world!\n"));
    my_printf("OK 1!\n");

    assert(3 == my_printf("%c!\n", 'H'));
    my_printf("OK 2!\n");

    assert(7 == my_printf("%c%c%c%c%c!\n", 'H', 'e', 'l', 'l', 'o'));
    my_printf("OK! 3\n");

    assert(17 == my_printf("Hello %s!\n", "QWASAR.IO"));
    my_printf("OK 4!\n");

    assert(17 == my_printf("Hello %s %s!\n", "Mr", "Gaetan"));
    my_printf("OK 5!\n");

    assert(20 == my_printf("NULL STRING %s!\n", (char *)NULL));
    my_printf("NULL OK!\n");

    assert(6 == my_printf("%d!\n", 1337));
    my_printf("NUM OK!\n");

    assert(16 == my_printf("%d - %d-%d!\n", 2048, 0, -1337));
    my_printf("NUMS OK!\n"); // q 16/23

    assert(5 == my_printf("%o!\n", 100));
    my_printf("Octal ok!\n"); // q 17/23

    // printf("%u\n!", -1337);
    // assert(6 == printf("%u\n!", -1337));

    // assert(6 == my_printf("%u\n!", -1337));
    // my_printf("UDEC ok!\n"); // q 19/23

    assert(3 == my_printf("%x!\n", 14));
    my_printf("HEX ok!\n"); //21/23
    
    int var = 69;
    my_printf("%p\n", &var);
    assert(16 == my_printf("%p!\n", &var));
    my_printf("PTR OK!\n");

    my_printf("ALL TESTS SUCCEEDED!\n"); */

    my_printf("Hello world!\n");
    my_printf("%c!\n", 'H');
    my_printf("%c-%c-%c-%c-%c!\n", 'H', 'e', 'l', 'l', 'o');
    my_printf("Testing %s!\n", "Single_string");
    my_printf("Testo el %s %s!\n", "Double", "String");
    my_printf("Should print NULL -  %s!\n", (char *)NULL); 
    my_printf("testing d - %d!\n", 1337);
    my_printf("testing multiple ds - %d - %d-%d!\n", 2048, 0, -1337);
    my_printf("testing o -%o!\n", 100);
    my_printf("testing x - %x!\n", 10);
    int var = 1;
    my_printf("%p\n", &var); 
    return 0;
}