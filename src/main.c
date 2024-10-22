#include "../inc/pathfinder.h"

int main(int argc, char *argv[]) {
    t_main *main = NULL;

    mx_val_cmd_args(argc);
    main = mx_create_main(argv);
    if (!main) {
        mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
    }

    mx_val_checker(main);
    mx_pathfinder_parse(main);
    mx_pathfinder_prepare(main);
    mx_pathfinder_algorithm(main);
    mx_pathfinder_prints(main);

    mx_free_main(main);

    return 0;
}

