#include "stdio.h"
#include <stdlib.h>
#include <zconf.h>

int main(){
    //Переменная process получит id процесса после выполнения fork
    pid_t process = fork();
    switch (process){
        case -1: //Если невозможно создать child process
            perror("Failed creating fork\n");
            exit(1);
        case 0: // Дочерний процесс
            break;
        default: // Родительский процесс
            execl("/bin/ls", "/bin/ls", NULL);
            break;
    }
    return 0;
}