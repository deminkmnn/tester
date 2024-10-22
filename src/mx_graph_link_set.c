#include "../inc/pathfinder.h"

void mx_graph_link_set(t_link **links, t_island *linked_island, int weight) {
    if (!links || !linked_island) {
        return;  
    }

    t_link *iter = *links;

    if (!iter) {  
        *links = mx_graph_link_create(linked_island);
        (*links)->weight = weight;
        return;
    }

    t_link *last_link = NULL;
    
    while (iter) {
        if (iter->linked_island == linked_island) {
            return; 
        }
        last_link = iter;
        iter = iter->next;
    }
    
    last_link->next = mx_graph_link_create(linked_island);
    last_link->next->weight = weight;
}
