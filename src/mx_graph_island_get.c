#include "../inc/pathfinder.h"

t_island *mx_graph_island_get(t_island **islands, char *name) {
    if (*islands == NULL) {
        *islands = mx_graph_island_create(name);
        return *islands;
    }

    t_island *current = *islands;
    t_island *last = NULL;

    while (current != NULL) {
        if (mx_strcmp(current->name, name) == 0) {
            mx_strdel(&name); 
            return current;   
        }
        last = current;      
        current = current->next;
    }

    last->next = mx_graph_island_create(name);
    return last->next;
}
