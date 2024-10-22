#include "../inc/pathfinder.h"

void mx_graph_island_add(t_island **islands, t_island *new_island) {
    if (islands == NULL || new_island == NULL) {
        return; 
    }

    if (*islands == NULL) {
        *islands = new_island; 
    } else {
        new_island->next = *islands;  
        *islands = new_island;  
    }
}
