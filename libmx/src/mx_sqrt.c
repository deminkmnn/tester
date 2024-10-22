#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if (x < 0) {
        return 0;  
    }

    for (int k = 1; k * k <= x; k++) {
        if (k * k == x) {
            return k; 
        }
    }

    return 0;  
}
