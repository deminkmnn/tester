#include "../inc/libmx.h"

char *mx_strdup(const char *s1)
{
    char *duplicates = mx_strnew(mx_strlen(s1));
    mx_strcpy(duplicates, s1);
    return duplicates;
}
