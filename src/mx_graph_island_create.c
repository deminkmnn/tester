#include "../inc/pathfinder.h"

t_island *mx_graph_island_create(char *name) {
    t_island *new_island = malloc(sizeof(t_island));
    if (new_island == NULL) {
        return NULL; 
    }

    new_island->name = name;     
    new_island->links = NULL;     
    new_island->next = NULL;     

    return new_island; 
}
