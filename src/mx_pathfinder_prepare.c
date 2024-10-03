#include "../inc/pathfinder.h"

void mx_pathfinder_prepare(t_main *main) {
    t_island *current_island = main->islands; 
    int island_index = 0; 

    while (current_island) {
        current_island->index = island_index; 

        current_island->paths = malloc(sizeof(t_path *) * main->count_island);
        if (!current_island->paths) {
            return; 
        }


        for (int j = 0; j < main->count_island; j++) {
            current_island->paths[j] = NULL; 
        }

        island_index++; 
        current_island = current_island->next;
    }
}
