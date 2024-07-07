#include <stdio.h>
#include <string.h>
#include <unistd.h>

int puts(const char *str)
{
    /**
     * With the write syscall, puts function
     * prints a string and a '\n' after it
     */
    write(1, str, strlen(str));
    write(1, "\n", 1);

    return 0;
}
