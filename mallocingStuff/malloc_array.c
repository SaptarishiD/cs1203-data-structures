#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    int* a;
    char* b;
    a = malloc(1000*sizeof(int));
    a[1] = 42;
    b = a;
    printf("%d\n", a[1]);
    printf("%d\n", b[4]);
    

    


}