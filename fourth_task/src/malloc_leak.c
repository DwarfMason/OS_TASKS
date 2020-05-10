#include "stdio.h"
#include "stdlib.h"

int main(){
    int *array = malloc(100 * sizeof(int));
    for (int i = 0; i < 100; i++)
        array[i] = i;
    return 0;
}