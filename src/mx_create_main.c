#include "../inc/pathfinder.h"

t_main *mx_create_main(char *argv[]) {
    t_main *main = malloc(sizeof(t_main));
    if (!main) {
        mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
        return NULL;
    }
    
    main->file = mx_open_file(argv);
    if (!main->file) {
        free(main);
        mx_printallerr(FILE_DOESNTEXIST, argv[1]);
        return NULL;
    }

    main->islands = NULL;
    main->count_island = 0;
    main->algorithm = mx_create_algorithm();


    if (!main->algorithm) {
        mx_free_file(main->file);
        free(main);
        mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
        return NULL;
    }

    return main;
}
