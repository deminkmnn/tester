#include "../inc/libmx.h"


char *mx_nbr_to_hex(unsigned long nbr) {
    if (nbr == 0) {
        char *zero_str = malloc(2); 
        if (zero_str == NULL) return NULL;
        zero_str[0] = '0';
        zero_str[1] = '\0';
        return zero_str;
    }

    unsigned long brief = nbr;
    int length = 0;


    while (brief != 0) {
        length++;
        brief /= 16;
    }

    char *hex_str = malloc(length + 1);
    if (hex_str == NULL) return NULL;

    hex_str[length] = '\0';


    while (nbr != 0) {
        unsigned long rem = nbr % 16;
        if (rem < 10) {
            hex_str[--length] = '0' + rem;
        } else {
            hex_str[--length] = 'a' + (rem - 10);
        }
        nbr /= 16;
    }

    return hex_str;
}
