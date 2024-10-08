#include "../inc/libmx.h"


void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n) {
    unsigned char *cdst = (unsigned char *)dst;
    const unsigned char *csrc = (const unsigned char *)src;

    for (size_t i = 0; i < n; i++) {
        cdst[i] = csrc[i];
    }

    return dst;
}
