#include "../inc/pathfinder.h"

void mx_val_check_end_line(char *array) {
    int l_number = 1;

    for (int i = 0; array[i] != '\0'; i++) {
        if (array[i] == '\n') {
            l_number++;
            if (array[i + 1] == '\n') {
                char *line_str = mx_itoa(l_number);
                mx_printallerr(INVALID_LINE, line_str);
                free(line_str); 
            }
        }
    }

    if (array[0] == '\n') {
        char *line_str = mx_itoa(1);
        mx_printallerr(INVALID_LINE, line_str);
        free(line_str); 
    }
}
