#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int count = 0;
    int in_word = 0;

    if (!str) {
        return -1; 
    }

    while (*str) {
        if (*str != c && in_word == 0) {
            in_word = 1; 
            count++;     
        } else if (*str == c) {
            in_word = 0;  
        }
        str++;
    }

    return count;
}
