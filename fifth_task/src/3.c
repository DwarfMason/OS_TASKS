#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <zconf.h>

void mytail(unsigned int n, const char *name) {
    int f;                 // переменная для файла
    struct stat file_stat; // структура для описани файла
    stat(name, &file_stat); // получаем описание нашего файла
    unsigned int block_size = file_stat.st_blksize; // Буффер чтение

    char *ans = malloc(block_size + 1); // выделяем память под ответ
    char *buf = malloc(block_size); // выделяем память под буфер чтения блока

    if ((f = open(name, O_RDONLY)) < 0) {
        printf("Error opening!");
        exit(0);
    }
    for (unsigned int i = 0;; i++) {
        long int offset = (long)(i + 1) * block_size; // высчитываем смещение блока

        // Если смещение > файла
        if (offset > file_stat.st_size)
            offset = file_stat.st_size;

        if (lseek(f, -offset, SEEK_END) == -1L) { // смещаемся на заданное смещение
            // с конца файла
            printf("Seek Error\n");
            exit(0);
        }
        int was_read = 0;
        if ((was_read = read(f, buf, block_size)) == 0) { // читаем блок
            printf("Read Error\n");
            exit(0);
        }
        for (long int j = 0; j < was_read; j++) { // бежимся по элементам блока
            if (buf[was_read - 1 - j] == '\n')  // если это переход строки -
                n--;                               // уменьшаем счётчик

            /* Если мы нашли нужное количество строк, выводим накопленные значения
             * в обратном порядке + освобождаем память, или если мы дошли до начала
             * файла, то выводим первый символ файла, а потом все накопленные значения
             * в обратном порядке + очищаем память.*/
            if ((n == 0) ||
                (((offset == file_stat.st_size)) && (j == (was_read - 1)))) {
                if (n != 0) {
                    printf("%c", buf[0]);
                }
                for (long int k = i * block_size + j - 1; k >= 0; k--) {
                    printf("%c", ans[k]);
                }
                free(ans);
                free(buf);
                return;
            }
            ans[i * block_size + j] =
                    buf[was_read - 1 - j]; // добавляем значение в ответ
        }
        /*Если же мы дошли до конца блока, то удлиняем строку нашего ответа
         * на ещё один блок*/
        if (!(ans = realloc(ans, (i + 2) * block_size))) {
            printf("Allocation error.");
            exit(1);
        }
    }
}

int main() {
    mytail(20, "test.txt");
    return 0;
}