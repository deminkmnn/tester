#include "../inc/pathfinder.h"

t_algorithm *mx_create_algorithm(void) {
    t_algorithm *algorithm = malloc(sizeof(t_algorithm));
    if (!algorithm) {
        return NULL; 
    }

    algorithm->start = NULL;
    algorithm->end = NULL;
    algorithm->start_remainder = NULL;

    return algorithm; 
}
