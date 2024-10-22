#include "../inc/pathfinder.h"

void mx_free_main(t_main *main) {
    if (!main) return;

    if (main->file) {
        mx_free_file(main->file);
    }

    if (main->islands) {
        mx_free_islands(main->islands);
    }

    if (main->algorithm) {
        mx_free_algorithm(main->algorithm);
    }

    free(main);
}
