#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float sum;
    sum = 0.1 + 0.1 + 0.1;
    printf("%f\n", sum); // should print 0.3 but instead prints 0.3 followed by some number of 0s
}