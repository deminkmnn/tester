#include "../inc/libmx.h"

static void swap(void **s1, void **s2) {
    void *brief = *s1;
    *s1 = *s2;
    *s2 = brief;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (lst && cmp){
        
        for (t_list *brief1 = lst; brief1; brief1 = brief1->next){

            for (t_list *brief2 = lst; brief2->next; brief2 = brief2->next){

                if (cmp(brief2->data, brief2->next->data)){

                    swap(&brief2->data, &brief2->next->data);  
                }
            }
        }
    }
    return lst;

}
