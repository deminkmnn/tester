#include "../inc/libmx.h"

void *mx_memmove(void *dst, void *src, size_t len) {
    unsigned char *cdst = (unsigned char *)dst;
    unsigned char *csrc = (unsigned char *)src;

    unsigned char *brief = (unsigned char *)malloc(len);
    if (brief == NULL) {
        return dst;
    }

    for (size_t i = 0; i < len; i++) {
        brief[i] = csrc[i];
    }

    for (size_t i = 0; i < len; i++) {
        cdst[i] = brief[i];
    }

    free(brief);

    return dst;
}
