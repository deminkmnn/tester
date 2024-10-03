#include "../inc/libmx.h"

void mx_str_reverse(char *s){
    int start = 0;
    int end = mx_strlen(s) - 1;
    char brief;

    while (start < end) {
      
        brief = s[start];
        s[start] = s[end];
        s[end] = brief;

        start++;
        end--;
    }
}
