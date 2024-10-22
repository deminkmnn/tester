#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (!s) {
        return NULL;
    }

    int word_count = 0;
    int i = 0;
    while (s[i]) {
        if (s[i] != c) {
            word_count++;
            while (s[i] && s[i] != c) {
                i++;
            }
        } else {
            i++;
        }
    }

    char **arr = (char **)malloc((word_count + 1) * sizeof(char *));
    if (!arr) {
        return NULL;
    }

    int j = 0;
    i = 0;
    while (s[i]) {
        if (s[i] != c) {
            int start = i;
            while (s[i] && s[i] != c) {
                i++;
            }
            int word_len = i - start;
            arr[j] = (char *)malloc((word_len + 1) * sizeof(char));
            if (!arr[j]) {
                while (j > 0) {
                    j--;
                    free(arr[j]);
                }
                free(arr);
                return NULL;
            }
            mx_strncpy(arr[j], &s[start], word_len);
            arr[j][word_len] = '\0';
            j++;
        } else {
            i++;
        }
    }

    arr[j] = NULL;
    return arr;
}
