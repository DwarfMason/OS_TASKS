#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
#include <unistd.h>
#include <libnet.h>

struct timeval t1, t2, t_ans;
const char* file = "file.txt";

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

void PosixWrite(){
    int file_desc = creat(file, S_IRWXU);
    for (long i = 0; i < 300000; i++)
        write(file_desc, " ", 1);
    close(file_desc);
}

void StdioWrite(){
    FILE* out = fopen(file, "w+");
    for(long i = 0; i < 300000; i++)
        fwrite(" ", 1, sizeof(" "), out);
    fclose(out);
}

int main(){
    start_time();
    PosixWrite();
    end_time();
    print_time("Posix writing time: ");
    remove(file);

    start_time();
    StdioWrite();
    end_time();
    print_time("stdio writing time: ");
    remove(file);
    return 0;
}

