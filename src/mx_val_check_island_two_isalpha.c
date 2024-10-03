#include "../inc/pathfinder.h"

void mx_val_check_island_two_isalpha(char **array) {
    for (int i = 1; array[i] != NULL; i++) {
        bool found_dash = false;

        for (int j = 0; array[i][j] != ',' && array[i][j] != '\0'; j++) {
            if (array[i][j] == '-') {
                found_dash = true;
                j++;  
            }
            if (found_dash && !mx_isalpha(array[i][j])) {
                char *line_str = mx_itoa(i + 1);
                mx_printallerr(INVALID_LINE, line_str);
                free(line_str);
            }
        }
    }
}

