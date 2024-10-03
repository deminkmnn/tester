#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t len) {
    unsigned char *ptr = (unsigned char *)b; 

    for (size_t k = 0; k < len; k++) {
        ptr[k] = (unsigned char)c; 
    }

    return b; 
}
