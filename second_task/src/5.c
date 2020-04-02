#include <stdlib.h>
#include <libnet.h>
#include <unistd.h>

int main(){
    pid_t process = fork();
    switch(process){
        case -1:
            printf("Не удалось создать дочерний процесс\n");
            exit(1);
        case 0:
            fclose(stdout);
            printf("Тестовый вывод дочернего процесса\n");
            break;
        default:
            printf("Тестовый вывод родительского процесса\n");
            break;
    }
    return 0;
}

