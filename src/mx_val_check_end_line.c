#include "../inc/pathfinder.h"

bool mx_val_check_end_line(char *array) {
    if (!array) return false;

    int l_number = 1;
    bool is_previous_newline = false;
    long long total_length_sum = 0;

    if (array[0] == '\n') {
        char *line_str = mx_itoa(1);
        if (line_str) {
            mx_printallerr(INVALID_LINE, line_str);
            free(line_str);
        } else {
            mx_printallerr(INVALID_LINE, "1");
        }
        return false;
    }

    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == '\n') {
            if (is_previous_newline) {
                char *line_str = mx_itoa(l_number);
                if (line_str) {
                    mx_printallerr(INVALID_LINE, line_str);
                    free(line_str);
                } else {
                    mx_printallerr(INVALID_LINE, "Unknown");
                }
                return false;
            }
            l_number++;
            is_previous_newline = true;
        } else {
            is_previous_newline = false;
        }
    }

    char **lines = mx_strsplit(array, '\n'); 
    for (int i = 1; lines[i] != NULL; i++) { 
        char **parts = mx_strsplit(lines[i], '-'); 
        if (parts[1] != NULL) {
            long length = mx_atoi(parts[1]); 
            if (length < 0) {
                mx_printallerr(INVALID_LINE, mx_itoa(i + 1)); 
                return false;
            }
            total_length_sum += length;
            if (total_length_sum > INT_MAX) {
                mx_printallerr(SUM_OF_BRIDGES_TOO_BIG, NULL); 
                return false;
            }
        }
        mx_del_strarr(&parts);
    }
    mx_del_strarr(&lines);

    return true;
}

