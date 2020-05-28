#include "stdlib.h"

int main(){
    int* data = malloc(100 * sizeof(int));
    data[101] = 0;
    return 0;
}