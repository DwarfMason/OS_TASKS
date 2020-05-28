#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int offset = 0; // счётчик смещений

void print_offset() { // печатает смещение
    for (unsigned int i = 0; i < offset; i++) {
        printf("   ");
    }
}

void rec_print_dir(const char *name_dir) { // рекурсивная функция обхода
    DIR *dir; // переменная для хранения дирректории
    struct dirent *entry; // структура хранения элемента дерриктории
    dir = opendir(name_dir); // открываем директорию

    if (!dir) { // проверяем успешность открытия
        printf("Error!");
        exit(0);
    }

    while ((entry = readdir(dir)) != NULL) { // пока есть что читать, читаем
        if((strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) == 0)
            continue;
        print_offset();
        printf("-%s", entry->d_name); // печатаем ребёнка
        if (entry->d_type == 4) {     // если это директория
            printf(":\n"); // печать двоеточия с переходом на новую строку
            char full_file_name[1024]; // переменная для полного пути к файлу
            snprintf(full_file_name, sizeof full_file_name, "%s%s/", name_dir,
                     entry->d_name); // склеиваем путь
            offset++;                // увеличиваем смещение
            rec_print_dir(full_file_name); // совершаем обход для ребёнка
            offset--;                      // уменьшаем смещение
        } else {
            printf("\n"); // просто переходим на новую строчку
        }
    };

    closedir(dir); // закрываем директорию
}

void print_dir(const char *dir) { // печатает дерево данной директории
    printf("-%s:\n", dir); // печатаем данную директорию
    offset = 1;            // задаём смещение
    rec_print_dir(dir);    // делаем обход
}

void print_this_dir(char* argv) { // печатает дерево текущей директории
    char *dir = argv; // устанавливаем текущую директорию
    printf("-%s:\n", dir); // печатаем текущую директорию
    offset = 1;            // задаём смещение
    char *pos = strrchr(dir, '6');
    if (pos)
        dir[pos-dir] = 0;
    rec_print_dir(dir);    // делаем обход
}

int rec_print_find(const char *name_dir, const char *name) {
    DIR *dir; // переменная для хранения дирректории
    struct dirent *entry; // структура хранения элемента дерриктории
    dir = opendir(name_dir); // открываем директорию

    if (!dir) { // проверяем успешность открытия
        printf("Error!");
        exit(0);
    }

    int any_was_print = 0; // если нашли хоть где-то
    while ((entry = readdir(dir)) != NULL) { // пока есть что читать, читаем
        if((strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) == 0)
            continue;
        int was_print = 0; // у данного ребёнка есть искомый
        if (entry->d_type == 4) { // если это директория
            char full_file_name[1024]; // переменная для полного пути к файлу
            snprintf(full_file_name, sizeof full_file_name, "%s%s/", name_dir,
                     entry->d_name); // склеиваем путь
            offset++;                // увеличиваем смещение
            int res =
                    rec_print_find(full_file_name, name); // совершаем обход для ребёнка
            offset--;         // уменьшаем смещение
            if (res) {        // если нашли
                print_offset(); // печатаем смещение
                if (!strcmp(entry->d_name, name)) { // если это искомый
                    printf("+");                      // ставим +
                } else {                            // иначе
                    printf("-");                      // ставим -
                }
                printf("%s\n", entry->d_name); // печатаем ребёнка
                any_was_print = was_print = 1; // обнавляем флаги
            }
        }
        if (!strcmp(entry->d_name, name) &&
            !was_print) { // искомое и ещё не печатали
            print_offset(); // печатаем смещение
            printf("+%s\n", entry->d_name); // печатаем ребёнка
            any_was_print = 1;              // обновляем флаг
        }
    };

    closedir(dir);        // закрываем директорию
    return any_was_print; // возвращаем результат
}

int print_find(char *dir, const char *name) {
    offset = 1;                               // задаём смещение
    char *buff = dir;
    char *pos = strrchr(buff, '6');
    if (pos)
        dir[pos-dir] = 0;
    int res = rec_print_find(buff, name); // делаем обход
    if (res) { // если удалось что либо найти
        printf("-%s:\n", buff); // печатаем данную директорию
    }
    return res; // возвращаем результат поиска
}

int main(int argc, char *argv[]) {
    //print_this_dir(*argv);
    print_find(*argv, "1");
    return 0;
}