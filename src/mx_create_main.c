#include "../inc/pathfinder.h"

t_main *mx_create_main(char *argv[]) {
    t_main *main = malloc(sizeof(t_main));
    if (!main) {
        return NULL; 
    }
    
    main->file = mx_open_file(argv);
    main->islands = NULL;
    main->count_island = 0;
    main->algorithm = mx_create_algorithm();

    return main;
}
