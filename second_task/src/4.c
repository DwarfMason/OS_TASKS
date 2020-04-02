#include "stdio.h"
#include <stdlib.h>
#include <zconf.h>
#include <wait.h>

void WaitChild(){
    printf("----------------------------------------\n");
    pid_t process = fork();
    switch (process){
        case -1: //Если невозможно создать child process
            perror("Не удалось создать дочерний процесс\n");
            exit(1);
        case 0: // Дочерний процесс
            printf("Возвращаемое значение wait(): %d\n", wait(NULL));
            printf("Тестовый вывод дочернего процесса (2)\n");
            exit(16);
        default:
            printf("Тестовый вывод родительского процесса (2)\n");
    }
}

int main() {
    int status;
    pid_t wait_state;
    //Переменная process получит id процесса после выполнения fork
    pid_t process = fork();
    switch (process) {
        case -1: //Если невозможно создать child process
            perror("Не удалось создать дочерний процесс\n");
            exit(1);
        case 0: // Дочерний процесс
            printf("Тестовый вывод дочернего процесса\n");
            exit(16);
        default: // Родительский процесс
            wait_state =  wait(&status);
            printf("Не равно нулю, если дочерний процесс нормально завершился:"
                   " %d\n",WIFEXITED(status));
            printf("Возвращает восемь младших битов завершенного процесса: %d\n",
                    WEXITSTATUS(status));
            printf("Возвращает истину, если дочерний процесс завершился от "
                   "неперехваченного сигнала: %d\n", WIFSIGNALED(status));
            if (WIFSIGNALED(status) != 0) printf("Номер сигнала, завершивший "
                                                 "процесс: %d\n", WTERMSIG(status));
            //Далее вывод 0, если ошибка и -1, если указано явно вернуть управление до завершения
            printf("wait() вернуло: %d\n", wait_state);
            printf("Тестовый вывод родительского процесса\n");
            break;
    }
    WaitChild();
    return 0;
}