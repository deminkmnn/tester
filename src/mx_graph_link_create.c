#include "../inc/pathfinder.h"

t_link *mx_graph_link_create(t_island *linked_island) {
    if (!linked_island) {
        return NULL;  
    }

    t_link *new_link = malloc(sizeof(t_link));
    if (!new_link) {
        return NULL;  
    }

    new_link->linked_island = linked_island;
    new_link->next = NULL;

    return new_link;
}
