#include "../inc/libmx.h"


void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len){
    const unsigned char *b = big;
    const unsigned char *l = little;
    
    if (little_len == 0 || big_len < little_len) {
        return NULL; 
    }

    for (size_t i = 0; i <= big_len - little_len; i++) {
        if (mx_memcmp(b + i, l, little_len) == 0) {
            return (void *)(b + i);
        }
    }

    return NULL; 
}

