#include "../inc/pathfinder.h"

void mx_val_check_delim(char **array) {
    for (int i = 1; array[i] != NULL; i++) {
        int d1 = 0;
        int d2 = 0;

        for (int j = 0; array[i][j] != '\0'; j++) {
            if (array[i][j] == '-') 
                d1++;
            else if (array[i][j] == ',' && d1 == 1)
                d2++;
        }

        if (d1 != 1 || d2 != 1) {
            char *line_num = mx_itoa(i + 1);
            mx_printallerr(INVALID_LINE, line_num);
            free(line_num); 
        }
    }
}
