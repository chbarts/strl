#include <stdio.h>
#include "strl.h"

int main(int argc, char *argv[])
{
    char buf[BUFSIZ];
    int i;

    buf[0] = '\0';

    for (i = 1; i < argc; i++)
        if (strlcat(buf, argv[i], sizeof(buf)) >= sizeof(buf))
            break;

    puts(buf);
    return 0;
}
