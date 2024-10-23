#include "../inc/pathfinder.h"

bool mx_val_sum_of_bridges(t_path *path) {
    if (!path) {
        return false;  
    }

    t_path *current_path = path;

    while (current_path) {
        if (!current_path->route) {
            return false; 
        }

        t_link *route = current_path->route;
        long long total_distance = 0;  

        while (route) {
            if (route->weight < 0) {  
                return false;  
            }

            if (total_distance + route->weight > LLONG_MAX) {
                mx_printallerr(SUM_OF_BRIDGES_TOO_BIG, NULL);  
                return false;
            }

            total_distance += route->weight;

            if (total_distance > INT_MAX) {  
                mx_printallerr(SUM_OF_BRIDGES_TOO_BIG, NULL);  
                return false;
            }
            
            route = route->next;
        }

        current_path = current_path->next;
    }
    return true;
}
