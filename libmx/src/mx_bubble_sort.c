#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int c = 0;

    for (int k = 0; k < size; ++k) {
        if (arr[k] == NULL) {
            return -1;
        }
    }

    for (int k = 0; k < size - 1; ++k) {
        for (int n = 0; n < size - 1 - k; ++n) {
            if (mx_strcmp(arr[n], arr[n + 1]) > 0) {
                char *brief = arr[n];
                arr[n] = arr[n + 1];
                arr[n + 1] = brief;

                ++c;
            }
        }
    }

    return c;
}
