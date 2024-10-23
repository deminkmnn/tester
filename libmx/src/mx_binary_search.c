#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count){

    (*count) = 0;
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;

    while (low <= high) {

        (*count)++;

        if (mx_strcmp(arr[mid], s) < 0) {
            low = mid + 1;
        }

        else if (mx_strcmp (arr[mid], s) == 0) {
            return mid;
        }

        else {
            high = mid - 1;
        }

    mid = (low + high) / 2;
    }

    if (low > high) {
        *count = 0;
        return -1;
    }

    return -1;
}
