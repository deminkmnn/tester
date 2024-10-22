#include "../inc/pathfinder.h"

char *mx_strrchr(const char *s, int c) {
    const char *ptr = s;
    char ch = (char)c;
    const char *last_occurrence = NULL;

    while (*ptr) {
        if (*ptr == ch) {
            last_occurrence = ptr;
        }
        ptr++;
    }

    return (char *)last_occurrence;
}
