#include "../inc/libmx.h"

int mx_list_size(t_list *list){
    int count_size = 0;
    t_list *brief = NULL;

    if (list) {
        brief = list;
        while (brief != NULL) {
            count_size++;
            brief = brief->next;
        }
    }

    return count_size;
}
