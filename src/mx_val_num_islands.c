#include "../inc/pathfinder.h"

void mx_val_num_islands(t_main *main) {
    t_island *iter = main->islands;
    int count = 0;

    while (iter) {
        count++;
        iter = iter->next;
    }
    if (main->count_island != count){
        mx_printallerr(INVALID_NUM_ISLANDS, NULL);
    }
}
