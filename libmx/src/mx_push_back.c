#include "../inc/libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *b_list = mx_create_node(data);
    t_list *brief = NULL;

    if (list == NULL || *list == NULL){
        *list = b_list;
    }

    else {
        brief = *list;
        while (brief->next != NULL)
            brief = brief->next;
        brief->next = b_list;
    }
    
}
