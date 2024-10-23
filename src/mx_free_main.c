#include "../inc/pathfinder.h"

void mx_free_main(t_main *main) {
    if (!main) return;

    if (main->file) {
        mx_free_file(main->file);
        main->file = NULL;
    }

    if (main->islands) {
        mx_free_islands(main->islands);
        main->islands = NULL;
    }

    /*if (main->algorithm) {
        mx_free_algorithm(main->algorithm);
        main->algorithm = NULL;
    }*/

    free(main);
    main = NULL;
}
