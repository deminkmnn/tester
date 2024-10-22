#include "../inc/pathfinder.h"

void mx_val_check_end_line(char *array) {
    int l_number = 1;
    int is_previous_newline = 0;

    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == '\n') {
            if (is_previous_newline) {
                char *line_str = mx_itoa(l_number);
                mx_printallerr(INVALID_LINE, line_str);
                free(line_str);
                return; 
            }
            l_number++;
            is_previous_newline = 1;
        } else {
            is_previous_newline = 0;
        }
    }

    if (array[0] == '\n') {
        char *line_str = mx_itoa(1);
        mx_printallerr(INVALID_LINE, line_str);
        free(line_str);
    }
}
