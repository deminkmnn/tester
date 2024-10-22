#include "../inc/pathfinder.h"

bool mx_val_check_delim(char **array) {
    if (!array) return false;  

    for (int i = 1; array[i] != NULL; i++) {
        int dash_count = 0;
        int comma_count = 0;
        bool dash_found = false;

        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == '-') {
                dash_count++;
                dash_found = true;
            }
            else if (array[i][j] == ',') {
                if (!dash_found || comma_count > 0) {
                    char *line_num = mx_itoa(i + 1);
                    if (line_num) {
                        mx_printallerr(INVALID_LINE, line_num);
                        free(line_num);
                    } else {
                        mx_printallerr(INVALID_LINE, "Unknown");
                    }
                    return false;
                }
                comma_count++;
            }
        }

        if (dash_count != 1 || comma_count != 1) {
            char *line_num = mx_itoa(i + 1);
            if (line_num) {
                mx_printallerr(INVALID_LINE, line_num);
                free(line_num);
            } else {
                mx_printallerr(INVALID_LINE, "Unknown");
            }
            return false;
        }
    }
    return true;
}
