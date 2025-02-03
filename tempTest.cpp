#include <stdio.h>
#include <stdlib.h>

int main(){
    int** a = (int**)malloc(12);
    *a[0] = 5;
    *(a+1) = *a;
    printf("%p, %p\n", a, *(a+1));
    return 0;
}
