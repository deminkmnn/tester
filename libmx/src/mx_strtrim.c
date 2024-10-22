#include "../inc/libmx.h"

bool mx_isspace(char c) {
    return (c == ' ' || (c >= '\t' && c <= '\r'));
}

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    while (mx_isspace(*str)) {
        str++;
    }

    if (*str == '\0') {
        return mx_strndup("", 0);
    }

    size_t len = mx_strlen(str);
    while (len > 0 && mx_isspace(str[len - 1])) {
        len--;
    }

    return mx_strndup(str, len);
}
