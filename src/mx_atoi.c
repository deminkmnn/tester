#include "../inc/pathfinder.h"


int mx_atoi(const char *str) {
    int k = -1;
    int result = 0;

    while (str[++k]) {
        if (mx_isdigit(str[k])){
            result = result * 10 + str[k] - '0';
        }
        if (!mx_isdigit(str[k])){
            return result;
        }
    }
    return result;
}
