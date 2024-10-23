#include "../inc/pathfinder.h"

bool mx_val_check_number(char **array) {
    if (!array) return false;  

    for (int i = 1; array[i] != NULL; i++) {
        bool f_comma = false;
        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == ',') {
                f_comma = true;
                continue;  
            }
            if (f_comma && !mx_isdigit(array[i][j])) {
                char *line_str = mx_itoa(i + 1);
                if (!line_str) {
                    mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
                    return false;
                }
                mx_printallerr(INVALID_LINE, line_str);
                free(line_str);
                return false;
            }
        }
    }
    return true;
}
