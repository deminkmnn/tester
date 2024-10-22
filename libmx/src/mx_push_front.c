#include "../inc/libmx.h"

void mx_push_front(t_list **list, void *data){
    t_list *f_list = mx_create_node(data);
    t_list *brief = NULL;

    if (list == NULL || *list == NULL){
        *list = f_list;
    }

    else {
        brief = *list;
        *list = f_list;
        f_list->next = brief;
    }

}
