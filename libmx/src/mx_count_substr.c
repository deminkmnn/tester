#include "../inc/libmx.h"


int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int sublen;

    if (!str || !sub) {
        return -1;
    }

    if (*sub == '\0') {
        return 0;
    }

    sublen = mx_strlen(sub);

    while (*str != '\0') {
        int i = 0;
        while (str[i] == sub[i] && sub[i] != '\0') {
            i++;
        }

        if (i == sublen) {
            count++;
            str += sublen;  
        } else {
            str++;  
        }
    }

    return count;
}
