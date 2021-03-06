#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    const char *name = "CMakeLists.txt"; // задаём имя файлу
    struct stat file_stat;
    if (stat(name, &file_stat)) { // получаем описание нашего файла
        printf("Error!\n");
        exit(0);
    }

    printf("Size: %li\n"
           "Number link: %lu\n"
           "Number block: %li\n",
           file_stat.st_size, file_stat.st_nlink, file_stat.st_blocks);

    return 0;
}

