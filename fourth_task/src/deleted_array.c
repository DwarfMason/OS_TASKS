#include "stdlib.h"
#include "stdio.h"

int main(){
    int* data = malloc(100 * sizeof(int));
    for (int i = 0; i < 100; i++)
        data[i] = i;
    free(data);
    printf("%d", data[7]);
    printf("%d", data[2]);
    return 0;
}