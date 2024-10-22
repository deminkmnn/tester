#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    char *ptr = s1;

    while (*ptr != '\0') {
        ptr++;
    }

    while (*s2 != '\0') {
        *ptr++ = *s2++;
    }

    *ptr = '\0';

    return s1;
}
