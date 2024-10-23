#include "../inc/libmx.h"


int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    static char *rem[255] = {NULL};
    char *buffer = (char *)malloc(buf_size + 1); 
    int bytes_read;
    int delim_index;

    if (fd < 0 || fd >= 255 || !lineptr || buf_size == 0 || !buffer) {
        free(buffer);
        return -2;
    }

    if (!rem[fd]) {
        rem[fd] = mx_strnew(0);
    }

    while ((bytes_read = read(fd, buffer, buf_size)) > 0) {
        buffer[bytes_read] = '\0';
        char *brief = mx_strjoin(rem[fd], buffer);
        mx_strdel(&rem[fd]); 
        rem[fd] = brief; 

        delim_index = mx_get_char_index(rem[fd], delim);
        if (delim_index != -1) {
            *lineptr = mx_strndup(rem[fd], delim_index);
            char *new_rem = mx_strdup(rem[fd] + delim_index + 1);
            mx_strdel(&rem[fd]); 
            rem[fd] = new_rem;
            free(buffer); 
            return delim_index;
        }
    }

    free(buffer);
    if (bytes_read == -1) {
        return -2;
    }


    if (rem[fd] && rem[fd][0] != '\0') {
        *lineptr = mx_strdup(rem[fd]);
        mx_strdel(&rem[fd]); 
        return -1;
    }

    return -1; 
}
