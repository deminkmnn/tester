#include "../inc/pathfinder.h"


bool mx_is_visited(t_link *visited, t_island *island) {
    t_link *current = visited;

    if (!current) {
        return false;
    }

    while (current) {
        if (mx_strcmp(current->linked_island->name, island->name) == 0) {
            return true;  
        }
        current = current->next;  
    }
    return false; 
}
void mx_check_is_shortest(t_path *path) {
    t_path *current_path = path;
    int min_distance = path->dist; 

    while (current_path) {
        if (current_path->dist < min_distance) {
            min_distance = current_path->dist; 
        }
        current_path->is_shortest = false; 
        current_path = current_path->next; 
    }

    current_path = path;
    while (current_path) {
        if (current_path->dist == min_distance) {
            current_path->is_shortest = true; 
        }
        current_path = current_path->next; 
    }
}

void mx_find_path(t_main *main, t_link *visited, int weight, t_path **paths) {
    t_link *current_link = main->algorithm->start->links; 
    t_link *visited_island = NULL; 
    t_path *brief_path = NULL; 

    if (mx_is_visited(visited, main->algorithm->start)) {
        return; 
    }

    visited_island = mx_graph_link_create(main->algorithm->start);
    visited_island->weight = weight;
    mx_graph_link_push_back(&visited, visited_island);

    if (main->algorithm->start == main->algorithm->end) {
        brief_path = mx_graph_path_create(visited);
        mx_graph_path_push_back(&paths[main->algorithm->end->index], brief_path);
    } 
    else {
        while (current_link) {
            main->algorithm->start = current_link->linked_island;
            mx_find_path(main, visited, current_link->weight, paths);
            current_link = current_link->next; 
        }
    }

    mx_graph_link_pop_back(&visited);
}


void mx_set_distances(t_path *path) {
    t_path *current_path = path;

    while (current_path) {
        if (!current_path->dist) {
            t_link *route = current_path->route; 
            int total_distance = 0;

            while (route) {
                total_distance += route->weight; 
                route = route->next; 
            }

            current_path->dist = total_distance; 
        }
        current_path = current_path->next; 
    }
}

void mx_pathfinder_algorithm(t_main *main) {
    main->algorithm->start = main->islands;
    t_link *visited = NULL;  
    t_path *current_path = NULL;  

    while (main->algorithm->start) {
        main->algorithm->end = main->algorithm->start->next;
        main->algorithm->start_remainder = main->algorithm->start;

        while (main->algorithm->end) {
            if (main->algorithm->start != main->algorithm->end) {
                mx_find_path(main, visited, 0, main->algorithm->start->paths);
                main->algorithm->start = main->algorithm->start_remainder;

                current_path = main->algorithm->start->paths[main->algorithm->end->index];
                mx_set_distances(current_path);
                mx_check_is_shortest(current_path);
            }
            main->algorithm->end = main->algorithm->end->next;
        }
        main->algorithm->start = main->algorithm->start->next;  
    }
}

