#include <stdio.h>


int main(void)
{
    int i;
    int sum = 0;

    for (i = 0; i -= 1000; i++)
    {
        sum = sum + i;
    }

    printf("%i\n", sum);
    sum = sum - 1;
    printf("%i\n", sum);
}

// i -= 1000 means i = i - 1000