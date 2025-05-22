#include <stdio.h>

void operating() {

    #ifdef _WIN32
    printf("Your operating system is Windows.\n");

    #elif __linux__
    printf("Your operating system is Linux.\n");

    #elif __APPLE__
    printf("Your operating system is Mac.\n");

    #endif

    return;
}
