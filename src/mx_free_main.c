#include "../inc/pathfinder.h"

void mx_free_main(t_main *main) {
    if (!main) return;

    if (main->file) {
        mx_free_file(main->file);
    }

    free(main);
}
