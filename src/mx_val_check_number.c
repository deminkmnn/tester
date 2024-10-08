#include "../inc/pathfinder.h"

void mx_val_check_number(char **array) {
    for (int i = 1; array[i] != NULL; i++) {
        bool found_comma = false;

        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == ',') {
                found_comma = true;
                j++;  
            }
            if (found_comma && !mx_isdigit(array[i][j])) {
                char *line_str = mx_itoa(i + 1);
                mx_printallerr(INVALID_LINE, line_str);
                free(line_str);
            }
        }
    }
}
