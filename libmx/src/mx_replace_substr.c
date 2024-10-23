#include "../inc/libmx.h"


char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }

    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);
    int count = 0;
    
    const char *brief = str;
    while ((brief = mx_strstr(brief, sub))) {
        count++;
        brief += sub_len;
    }

    int new_len = mx_strlen(str) + count * (replace_len - sub_len);
    char *new_str = (char *)malloc(new_len + 1); 
    if (!new_str) {
        return NULL;
    }

    char *ptr = new_str;
    
    while (*str) {
        const char *pos = mx_strstr(str, sub);
        if (pos) {
            int copy_len = pos - str;
            mx_strncpy(ptr, str, copy_len);
            ptr += copy_len;
            
            mx_strcpy(ptr, replace);
            ptr += replace_len;
            
            str = pos + sub_len;
        } else {
            mx_strcpy(ptr, str);
            break;
        }
    }

    return new_str;
}
