#include "../inc/pathfinder.h"

bool mx_val_check_duplicate_bridges(char **array) {
    if (!array) return false;

    for (int i = 1; array[i] != NULL; i++) {
        for (int j = i + 1; array[j] != NULL; j++) {
            char *bridge1 = mx_strdup(array[i]);
            char *bridge2 = mx_strdup(array[j]);
            
            if (!bridge1 || !bridge2) {
                mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
                free(bridge1);  // Safe to free even if NULL
                free(bridge2);
                return false;
            }

            char *dash1 = mx_strchr(bridge1, '-');
            char *comma1 = mx_strchr(bridge1, ',');
            char *dash2 = mx_strchr(bridge2, '-');
            char *comma2 = mx_strchr(bridge2, ',');

            if (!dash1 || !comma1 || !dash2 || !comma2) {
                free(bridge1);
                free(bridge2);
                continue;
            }

            *dash1 = *comma1 = *dash2 = *comma2 = '\0';

            char *island1_1 = bridge1;
            char *island1_2 = dash1 + 1;
            char *island2_1 = bridge2;
            char *island2_2 = dash2 + 1;

            if ((mx_strcmp(island1_1, island2_1) == 0 && mx_strcmp(island1_2, island2_2) == 0) ||
                (mx_strcmp(island1_1, island2_2) == 0 && mx_strcmp(island1_2, island2_1) == 0)) {
                char *line_str = mx_itoa(j + 1);
                if (!line_str) {
                    mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
                    free(bridge1);
                    free(bridge2);
                    return false;
                }
                mx_printallerr(DUPLICATE_BRIDGE, line_str);
                free(line_str);
                free(bridge1);
                free(bridge2);
                return false;
            }

            free(bridge1);
            free(bridge2);
        }
    }
    return true;
}
