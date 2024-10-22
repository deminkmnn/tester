#include "../inc/pathfinder.h"

void mx_val_check_island_two_isalpha(char **array) {
    for (int i = 1; array[i] != NULL; i++) {
        bool f_dash = false;

        for (int j = 0; array[i][j] != ',' && array[i][j] != '\0'; j++) {
            if (array[i][j] == '-') {
                f_dash = true;
                j++;
            }
            if (f_dash && !mx_isalpha(array[i][j])) {
                char *line_str = mx_itoa(i + 1);
                if (!line_str) {
                    mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
                    return;
                }
                mx_printallerr(INVALID_LINE, line_str);
                free(line_str);
            }
        }
    }
}