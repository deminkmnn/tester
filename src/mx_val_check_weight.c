#include "../inc/pathfinder.h"


void mx_val_check_weight(int i, int weight) {
    if (weight < -1){
        mx_printallerr(INVALID_LINE, mx_itoa(i + 1));
    }
}
