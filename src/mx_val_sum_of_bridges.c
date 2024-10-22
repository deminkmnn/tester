#include "../inc/pathfinder.h"

#include <limits.h> 
void mx_val_sum_of_bridges(t_path *path) {
    t_path *current_path = path;

    while (current_path) {
        t_link *route = current_path->route;
        long long total_distance = 0;

        while (route) {
            total_distance += route->weight;
            if (total_distance > INT_MAX) {
                mx_printallerr(SUM_OF_BRIDGES_TOO_BIG, NULL);
                return; 
            }
            route = route->next;
        }

        current_path = current_path->next;
    }
}
