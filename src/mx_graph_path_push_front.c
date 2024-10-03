#include "../inc/pathfinder.h"

void mx_graph_path_push_front(t_path **paths, t_path *path) {
    if (paths == NULL || path == NULL) {
        return;
    }

    if (*paths == NULL) {
        *paths = path;
    } else {
        path->next = *paths; 
        *paths = path; 
    }
}
