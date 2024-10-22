#include "../inc/pathfinder.h"

static bool save_islands(t_island *island1, t_island *island2, int weight, int i) {
    mx_graph_link_set(&island1->links, island2, weight);
    mx_graph_link_set(&island2->links, island1, weight);
    return mx_val_check_weight(i, weight);
}


void mx_pathfinder_parse(t_main *main) {
    char **split_line = NULL;
    char **split_comma = NULL;
    t_island *island1 = NULL;
    t_island *island2 = NULL;
    int weight;

    for (int i = 1; main->file->array[i] != NULL; i++) {
        split_line = mx_strsplit(main->file->array[i], '-');
        if (!split_line) {
            mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
            return;
        }

        island1 = mx_graph_island_get(&main->islands, mx_strdup(split_line[0]));
        if (!island1) {
            mx_del_strarr(&split_line);
            mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
            return;
        }

        split_comma = mx_strsplit(split_line[1], ',');
        if (!split_comma) {
            mx_del_strarr(&split_line);
            mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
            return;
        }

        island2 = mx_graph_island_get(&main->islands, mx_strdup(split_comma[0]));
        if (!island2) {
            mx_del_strarr(&split_line);
            mx_del_strarr(&split_comma);
            mx_printallerr(MEMORY_ALLOCATION_ERROR, NULL);
            return;
        }

        weight = mx_atoi(split_comma[1]);

        save_islands(island1, island2, weight, i);

        mx_del_strarr(&split_line);
        mx_del_strarr(&split_comma);
    }

    mx_val_num_islands(main);
}
