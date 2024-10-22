#include "../inc/pathfinder.h"

void mx_free_islands(t_island *islands) {
    t_island *current = islands;
    t_island *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
