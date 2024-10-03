#include "../inc/pathfinder.h"


void mx_graph_link_pop_back(t_link **links) {
    if (!links || !*links) {
        return;  
    }

    t_link *l = *links;

    if (!l->next) {
        l->linked_island = NULL;  
        free(l);  
        *links = NULL;  
        return;
    }

    while (l->next->next) {
        l = l->next;
    }


    l->next->linked_island = NULL;  
    free(l->next);  
    l->next = NULL;  
}
