#include "../inc/libmx.h"

void mx_swap(char **arr, int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) {
        return -1;
    }
    
    int swaps = 0;

    if (left < right) {
        int b = left;
        int k = right;
        char *pivot = arr[(left + right) / 2];

        while (b <= k) {
            while (mx_strlen(arr[b]) < mx_strlen(pivot)) b++;
            while (mx_strlen(arr[k]) > mx_strlen(pivot)) k--;

            if (b <= k) {
                if (b < k) {
                    mx_swap(arr, b, k);
                    swaps++;
                }
                b++;
                k--;
            }
        }

        swaps += mx_quicksort(arr, left, k);
        swaps += mx_quicksort(arr, b, right);
    }

    return swaps;
}
