#include "../inc/pathfinder.h"

t_path *mx_graph_path_create(t_link *route) {
    if (!route) {
        return NULL; 
    }
  
    t_path *path = mx_memalloc_zero(sizeof(t_path));
    if (!path) {
        return NULL; 
    }

    path->route = mx_graph_link_create(route->linked_island);
    if (!path->route) {
        free(path); 
        return NULL;
    }
    path->route->weight = route->weight;
    path->next = NULL;

    t_link *iter = route->next; 
    t_link *current_ptr = path->route;

    while (iter) {
        t_link *new_link = mx_graph_link_create(iter->linked_island);
        if (!new_link) {
            mx_graph_link_pop_back(&path->route); 
            free(path);
            return NULL;
        }
        new_link->weight = iter->weight;

        current_ptr->next = new_link; 
        current_ptr = new_link; 
        iter = iter->next; 
    }

    return path; 
}
