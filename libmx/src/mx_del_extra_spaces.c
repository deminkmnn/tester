#include "../inc/libmx.h"

bool mx_isspace(char c) {
    return (c == ' ' || (c >= '\t' && c <= '\r'));
}

char *mx_del_extra_spaces(const char *str) {
    if (!str) {
        return NULL;
    }

    char *mem = mx_strnew(mx_strlen(str));  
    int i = 0;
    int j = 0;
    bool space_added = false;

    
    while (mx_isspace(str[i])) {
        i++;
    }

    while (str[i]) {
        if (!mx_isspace(str[i])) {
            mem[j++] = str[i];
            space_added = false; 
        } else if (!space_added) {
            mem[j++] = ' ';  
            space_added = true; 
        }
        i++;
    }

    if (j > 0 && mem[j - 1] == ' ') {
        j--;
    }

    mem[j] = '\0'; 

    char *brief = mx_strtrim(mem);
    mx_strdel(&mem); 
    return brief;
}
