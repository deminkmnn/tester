#include "../inc/libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {

    if (hex == NULL) {
        return 0;
    }

    int j = 0;

    if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) {
        hex += 2;
    }

    while (hex[j] != '\0') {
        j++;
    }

    unsigned long res = 0;
    unsigned long dec = 1;

    for (int i = j - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            res += ((hex[i] - '0') * dec);
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            res += ((hex[i] - 'A' + 10) * dec);
        } 
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            res += ((hex[i] - 'a' + 10) * dec);
        } 
        else {
            return 0;
        }
        dec *= 16;
    }

    return res;
}
