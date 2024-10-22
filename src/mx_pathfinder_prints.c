#include "../inc/pathfinder.h"

static t_link *get_end_link(t_link *route) {
    t_link *current_link = route;

    while (current_link && current_link->next) {
        current_link = current_link->next;
    }

    return current_link; 
}

static void print_route(t_link *route) {
    if (!route) {
        mx_printstr("Route: None\n");
        return;
    }

    mx_printstr("Route: ");
    
    t_link *current_link = route;
    while (current_link) {
        mx_printstr(current_link->linked_island->name);

        if (current_link->next) {
            mx_printstr(" -> ");
        }
        current_link = current_link->next;
    }
    mx_printchar('\n');
}

static void print_distance(t_link *route) {
    t_link *rt = route->next;
    int distance = 0;

    mx_printstr("Distance: ");
    if (!rt->next)
        mx_printint(rt->weight);
    else
        while (rt) {
            distance += rt->weight;
            if (rt->next) {
                mx_printint(rt->weight);
                mx_printstr(" + ");
            }
            else {
                mx_printint(rt->weight);
                mx_printstr(" = ");
                mx_printint(distance);
            }
            rt = rt->next;
        }
    mx_printchar('\n');
}


static void print_paths(t_path *path) {
    while (path) {
        if (path->is_shortest) {
            t_link *end_link = get_end_link(path->route);

            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(path->route->linked_island->name);
            mx_printstr(" -> ");
            mx_printstr(end_link->linked_island->name);
            mx_printstr("\n");

            print_route(path->route);
            print_distance(path->route);
            mx_printstr("========================================\n");
        }
        path = path->next;
    }
}

void mx_pathfinder_prints(t_main *main) {
    if (!main || !main->islands) return;

    t_island *current_island = main->islands;

    while (current_island) {
        for (int i = 0; i < main->count_island; i++) {
            t_path *current_path = current_island->paths[i];
            if (current_path) {
                print_paths(current_path);
            }
        }
        current_island = current_island->next;
    }
    mx_free_main(main);
}
