#include "../inc/pathfinder.h"

void mx_pathfinder_prepare(t_main *main) {
    if (!main || !main->islands) return;

    t_island *current_island = main->islands; 
    int island_index = 0; 

    while (current_island) {
        current_island->index = island_index; 

        current_island->paths = malloc(sizeof(t_path *) * main->count_island);
        if (!current_island->paths) {
            mx_free_main(main);
            exit(EXIT_FAILURE);
        }

        for (int j = 0; j < main->count_island; j++) {
            current_island->paths[j] = NULL; 
        }

        island_index++; 
        current_island = current_island->next;
    }
}

