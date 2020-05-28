#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include <unistd.h>
#include <libnet.h>

struct timeval t1, t2, t_ans;

void start_time() {
    t1.tv_sec = t1.tv_usec = t1.tv_sec = t1.tv_usec = 0; // обнуляем.
    gettimeofday(&t1, NULL);
}

void end_time() {
    gettimeofday(&t2, NULL);
    t_ans.tv_sec = t2.tv_sec - t1.tv_sec;
    if (t2.tv_usec < t1.tv_usec) {
        t_ans.tv_sec--;
        t_ans.tv_usec = 1e6;
    } else {
        t_ans.tv_usec = 0;
    }
    t_ans.tv_usec += t2.tv_usec - t1.tv_usec;
}

void print_time(const char *mess) { // выводим разницу во времени
    printf(mess);
    printf("%li s %li micros\n", t_ans.tv_sec, t_ans.tv_usec);
}

int main() {
    const char* file = "file.txt";

    start_time();
    int file_desc = creat(file, S_IRWXU);
    end_time();
    print_time("File creation: ");

    if ( file_desc == -1) {
        printf("Невозможно создать файл");
        exit(1);
    }

    start_time();
    if (write(file_desc, "Символы для заполнения", 300) != 300) {
        printf("Ошибка записи!");
        exit(1);
    }
    end_time();
    print_time("Writing time:");

    start_time();
    fsync(file_desc); // fflush для FILE*. Заменено на аналог
    end_time();
    print_time("Flush time: ");

    start_time();
    close(file_desc);
    end_time();
    print_time("Close time: ");

    start_time();
    remove(file);
    end_time();
    print_time("Removal time: ");
    return 0;
}
