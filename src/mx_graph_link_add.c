#include "../inc/pathfinder.h"

void mx_graph_link_add(t_link **links, t_link *new_link) {
    if (links == NULL || new_link == NULL) {
        return;  
    }

    if (*links == NULL) {
        *links = new_link; 
    } else {
        new_link->next = *links;  
        *links = new_link;  
    }
}
