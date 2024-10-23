#include "../inc/pathfinder.h"

bool mx_check_line_validity(char *array) {
    if (!array) return false;

    char **lines = mx_strsplit(array, '\n'); 

    for (int i = 1; lines[i] != NULL; i++) { 
        char **parts = mx_strsplit(lines[i], '-');

        if (!parts[0] || !parts[1]) {
            mx_printallerr(INVALID_LINE, mx_itoa(i + 1)); 
            mx_del_strarr(&parts);
            mx_del_strarr(&lines);
            return false;
        }


        char **name_and_length = mx_strsplit(parts[1], ',');
        if (!name_and_length[0] || !name_and_length[1]) {
            mx_printallerr(INVALID_LINE, mx_itoa(i + 1));
            mx_del_strarr(&name_and_length);
            mx_del_strarr(&parts);
            mx_del_strarr(&lines);
            return false;
        }

        if (mx_strcmp(parts[0], name_and_length[0]) == 0) {
            mx_printallerr(INVALID_LINE, mx_itoa(i + 1)); 
            mx_del_strarr(&name_and_length);
            mx_del_strarr(&parts);
            mx_del_strarr(&lines);
            return false;
        }


        mx_del_strarr(&name_and_length);
        mx_del_strarr(&parts);
    }


    mx_del_strarr(&lines);
    return true;
}
