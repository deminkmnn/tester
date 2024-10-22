#include "../inc/pathfinder.h"

bool mx_val_check_end_line(char *array) {
    if (!array) return false;  

    int l_number = 1;
    bool is_previous_newline = false;

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

    return true;
}
