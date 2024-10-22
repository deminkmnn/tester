#include "../inc/libmx.h"

void mx_pop_back(t_list **head) {
    t_list *brief = NULL;

    if (head == NULL || *head == NULL){
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
    }

    else {
        brief = *head;
        while (brief && brief->next->next != NULL){
            brief = brief->next;
        }
        free(brief->next);
        brief->next = NULL;
    }
}
