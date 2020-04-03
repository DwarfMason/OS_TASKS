#include <stdio.h>
#include <zconf.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char **argv) {
    int size_to_allocate = 0;
    printf("Current process id: %d\n", getpid());
    if (argc == 1)
        scanf("%d", &size_to_allocate);
    else
        size_to_allocate = atoi(argv[1]);
        long final_size = size_to_allocate * 1024 * 1024;
    char *array = malloc(final_size);
    printf("Memory was allocated successfully: %dMb\n", size_to_allocate);
    while (true) {
        for (int i = 0; i < final_size; i++)
            array[i] = rand();
    }
    return 0;
}
