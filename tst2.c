#include <stdlib.h>
#include <stdio.h>
#include "strl.h"

int main(int argc, char *argv[])
{
    char *buf;
    int len, i;

    if (1 == argc) {
        return 0;
    }

    if ((len = atoi(argv[1])) <= 0) {
        return 0;
    }

    if ((buf = malloc(len)) == NULL) {
        return 0;
    }

    buf[0] = '\0';

    for (i = 2; i < argc; i++)
        if (strlcat(buf, argv[i], len) >= len)
            break;

    puts(buf);
    free(buf);
    return 0;
}
