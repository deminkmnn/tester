#include "../inc/pathfinder.h"

t_pair *create_pair(const char *island1, const char *island2, int distance) {
    t_pair *pair = malloc(sizeof(t_pair));
    pair->island1 = mx_strdup(island1);  
    pair->island2 = mx_strdup(island2);
    pair->distance = distance;
    pair->next = NULL;
    return pair;
}

void free_pair(t_pair *pair) {
    free(pair->island1);  
    free(pair->island2);  
    free(pair);           
}

bool check_and_add_pair(t_pair **head, const char *island1, const char *island2, int distance) {
    t_pair *current = *head;
    while (current) {
        if ((mx_strcmp(current->island1, island1) == 0 && mx_strcmp(current->island2, island2) == 0) ||
            (mx_strcmp(current->island1, island2) == 0 && mx_strcmp(current->island2, island1) == 0)) {
            if (current->distance != 0) {
                return false;
            }
        }
        current = current->next;
    }
    t_pair *new_pair = create_pair(island1, island2, distance);
    new_pair->next = *head;
    *head = new_pair;
    return true;
}

bool mx_check_duplicate_directions(t_main *main) {
    t_pair *pairs = NULL;
    char **split_line = NULL;
    char **split_comma = NULL;
    int weight;

    for (int i = 1; main->file->array[i] != NULL; i++) {
        split_line = mx_strsplit(main->file->array[i], '-');
        if (!split_line) continue;

        split_comma = mx_strsplit(split_line[1], ',');
        if (!split_comma) {
            mx_del_strarr(&split_line);  
            continue;
        }

        weight = mx_atoi(split_comma[1]);


        if (!check_and_add_pair(&pairs, split_line[0], split_comma[0], weight)) {
            mx_printallerr(INVALID_LINE, mx_itoa(i + 1));
            mx_del_strarr(&split_line);
            mx_del_strarr(&split_comma);


            while (pairs) {
                t_pair *temp = pairs;
                pairs = pairs->next;
                free_pair(temp);
            }
            return false;
        }


        mx_del_strarr(&split_line);
        mx_del_strarr(&split_comma);
    }


    while (pairs) {
        t_pair *temp = pairs;
        pairs = pairs->next;
        free_pair(temp);
    }
    return true;
}
