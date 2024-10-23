#include "../inc/pathfinder.h"

bool mx_val_check_weight(int i, int weight) {
    if (weight < 0 || weight > INT_MAX - 1) {
        char *line = mx_itoa(i + 1);
        if (!line) {
            mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
            return false;
        }
        mx_printallerr(INVALID_LINE, line);
        free(line);
        return false;
    }
    return true;
}
