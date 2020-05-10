#include <stdio.h>

int main(){

    int *a = NULL;
    //нельзя разименовать null. Ошибка
    printf("%d", *a);
    return 0;
}