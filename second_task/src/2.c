#include "stdio.h"
#include <stdlib.h>
#include <zconf.h>
#include <libnet.h>

int main(){
    //Переменная process получит id процесса после выполнения fork
    pid_t process = fork();
    switch (process){
        case -1: //Если невозможно создать child process
            perror("Failed creating fork\n");
            exit(1);
        case 0: // Дочерний процесс
            printf("Hello! ");
            //Сигнал на продолжение работы
            kill(process, SIGCONT);
            break;
        default: // Родительский процесс
            //Сигнал остановки процесса
            raise(SIGSTOP);
            printf("Goodbye!");
            break;
    }
    return 0;
}