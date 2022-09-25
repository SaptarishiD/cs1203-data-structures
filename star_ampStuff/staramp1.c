#include <stdio.h>

int main(void)
{
    int* x;
    int y = 4;
    x = &y;
    int* a;
    int b = 5;
    a = &b;

    int* s = a - x; //incompatible integer to pointer conversion initializing 'int *' with an expression of type 'long
                    // for + * and / was showing invalid operands to binary expression
    printf("%i\n", a);
    printf("%i\n", x);
    printf("%i\n", s); //why is s always -4
}