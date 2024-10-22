#include "../inc/libmx.h"


void *mx_realloc(void *ptr, size_t size) {
    if (size == 0) {
        free(ptr);
        return NULL;  
    }

    if (ptr == NULL) {
        return malloc(size);  
    }

    void *new_ptr = malloc(size);
    if (new_ptr == NULL) {
        return NULL; 
    }

    size_t old_size = 0; 

    size_t size_to_copy = old_size < size ? old_size : size;
    mx_memcpy(new_ptr, ptr, size_to_copy);

    free(ptr);

    return new_ptr;
}

