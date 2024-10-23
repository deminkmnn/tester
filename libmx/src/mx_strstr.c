#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (!*needle) {
        return (char *)haystack;
    }

    for (const char *h = haystack; *h; h++) {
        const char *h_iter = h;
        const char *n_iter = needle;

        while (*n_iter && *h_iter == *n_iter) {
            h_iter++;
            n_iter++;
        }

        if (!*n_iter) {
            return (char *)h;
        }
    }

    return NULL;  
}
