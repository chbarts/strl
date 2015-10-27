#include <string.h>
#include "strl.h"

size_t strlcpy(char *destination, const char *source, size_t size)
{
    size_t i;

    if (0 == size) {
        return 0;
    }

    for (i = 0; i < size - 1; i++) {
        if ('\0' == source[i]) {
            break;
        } else {
            destination[i] = source[i];
        }
    }

    destination[i + 1] = '\0';

    return i;
}

size_t strlcat(char *destination, const char *source, size_t size)
{
    size_t len;

    for (len = 0; len < size; len++) {
        if ('\0' == destination[len]) {
            break;
        }
    }

    return len + strlcpy(destination + len, source, size - len);
}
