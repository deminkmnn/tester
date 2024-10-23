#include "../inc/libmx.h"

int file_len(const char *file) {
    int flen = open(file, O_RDONLY);
    int len = 0;
    char buf;

    if (flen < 0) {
        return -1;
    }

    while (read(flen, &buf, 1) > 0) {
        len++;
    }

    close(flen);
    return len;
}

char *mx_file_to_str(const char *file) {
    int fl = open(file, O_RDONLY);
    int sz = 0;
    int size = 0;

    if (fl == -1) {
        return NULL; 
    }

    size = file_len(file);
    if (size == 0) {
        close(fl); 
        return NULL;
    }

    char *newstr = mx_strnew(size); 
    if (!newstr) {
        close(fl);  
        return NULL;
    }

    sz = read(fl, newstr, size);  
    if (sz < 0) {
        free(newstr); 
        close(fl);
        return NULL;
    }

    close(fl);  
    return newstr;
}
