#include "../inc/pathfinder.h"

void *mx_memalloc_zero(size_t size) {
    void *ptr = malloc(size); 
    if (ptr) {
        mx_memset(ptr, '\0', size); 
    }
    return ptr; 
}
