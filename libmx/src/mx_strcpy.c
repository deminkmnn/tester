#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *original_dst = dst;
    while ((*dst++ = *src++));

    return original_dst;
}
