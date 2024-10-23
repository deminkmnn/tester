#include "../inc/pathfinder.h"

void mx_graph_path_push_back(t_path **paths, t_path *path) {
    if (paths == NULL) {
        return;
    }
    
    if (*paths == NULL) {
        *paths = path; 
    } else {
        t_path *current = *paths; 
        
        while (current->next != NULL) {
            current = current->next; 
        }
        
        current->next = path; 
    }
}
