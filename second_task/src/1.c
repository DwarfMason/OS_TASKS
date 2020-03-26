#include "stdio.h"
#include <stdlib.h>
#include <zconf.h>

int main(){
    char x = 100;
    //Переменная process получит id процесса после выполнения fork
    pid_t process = fork();
    switch (process){
        case -1: //Если невозможно создать child process
            perror("Failed creating fork\n");
            exit(1);
        case 0: // Дочерний процесс
            printf("Child x validation: %d\n", x);
            x++;
            printf("Child x after child inc: %d\n", x);
            break;
        default: // Родительский процесс
            printf("Parent x validation: %d\n", x);
            x++;
            printf("Parent x after inc: %d\n", x);
            break;
    }
    return 0;
}