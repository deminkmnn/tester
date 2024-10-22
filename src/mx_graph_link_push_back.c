#include "../inc/pathfinder.h"

void mx_graph_link_push_back(t_link **links, t_link *link) {
    if (!links || !link) {
        return;
    }

    if (!*links) {
        *links = link;
        return;
    }

    t_link *iter = *links;

    while (iter->next) {
        iter = iter->next;
    }

    iter->next = link;
}
