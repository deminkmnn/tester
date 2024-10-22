#include "../inc/pathfinder.h"

void mx_free_algorithm(t_algorithm *algorithm) {
    if (!algorithm) return;

    if (algorithm->start) {
        free(algorithm->start);
    }

    if (algorithm->end) {
        free(algorithm->end);
    }

    if (algorithm->start_remainder) {
        free(algorithm->start_remainder);
    }

    free(algorithm);
}
