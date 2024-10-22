#include "../inc/pathfinder.h"


char **mx_open_file_to_array(char *file) {
    char *filetoarr = NULL;
    char **array = NULL;

    filetoarr = mx_file_to_str(file);
    array = mx_strsplit(filetoarr, '\n');
    mx_strdel(&filetoarr);
    return array;
}
