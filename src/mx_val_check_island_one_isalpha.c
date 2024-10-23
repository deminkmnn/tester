#include "../inc/pathfinder.h"

bool mx_val_check_island_one_isalpha(char **array) {
    for (int i = 1; array[i] != NULL; i++) {
        for (int j = 0; array[i][j] != '-' && array[i][j] != '\0'; j++) {
            if (!mx_isalpha(array[i][j])) {
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


        if (!mx_isalpha(array[i][0])) {
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
    return true;
}
