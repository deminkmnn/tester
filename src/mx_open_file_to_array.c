#include "../inc/pathfinder.h"

char **mx_open_file_to_array(char *file) {
    char *filetoarr = mx_file_to_str(file);
    

    if (!filetoarr) {
        return NULL;  
    }

    char **array = mx_strsplit(filetoarr, '\n');
    

    mx_strdel(&filetoarr);

    if (!array) {
        return NULL;  
    }

    return array;
}
