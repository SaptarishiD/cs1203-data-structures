#include <stdio.h>

int main(void)
{
    // int x = 3;
    // int* y;
    // y = &x;
    // printf("%d\n", y);





    int x = 3;

    int *y; //write * pehle or baad mein 

    y = &x;

    *y = *y + 1;
    printf("%d\n", *y);
    printf("%d\n", x);
}