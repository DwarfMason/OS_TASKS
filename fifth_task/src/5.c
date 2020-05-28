#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void myls(const char *name_dir, int l_flag) {
    DIR *dir; // переменная для хранения дирректории
    struct dirent *entry; // структура хранения элемента дерриктории
    dir = opendir(name_dir); // открываем директорию

    if (!dir) { // проверяем успешность открытия
        printf("Error!");
        exit(0);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != 4) {       // если это не директория
            printf("-%s", entry->d_name); // выводим имя
            if (l_flag) {
                char full_file_name[1024];
                snprintf(full_file_name, sizeof full_file_name, "%s%s", name_dir,
                         entry->d_name);
                struct stat file_stat; // структура для описани файла
                if (stat(full_file_name,
                         &file_stat)) { // получаем описание нашего файла
                    printf("\nError!\n");
                    exit(0);
                }
                /*Выводим дополнительную информацию о файле.*/
                printf(" (Size: %li, Number link: %lu, Number block: %li, UID: %u, "
                       "GID: %u, Mode: %u)",
                       file_stat.st_size, file_stat.st_nlink, file_stat.st_blocks,
                       file_stat.st_uid, file_stat.st_gid, file_stat.st_mode);
            }
            printf("\n");
        }
    };

    closedir(dir);
}

int main(int argc, char *argv[]) {
    myls("./", 1);
    return 0;
}