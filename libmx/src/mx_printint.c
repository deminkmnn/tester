#include "../inc/libmx.h"

void mx_printint(int n) {

    if (n == -2147483648) {
        const char *min_int = "-2147483648";
        write(1, min_int, 11);
        return;
    }
    
    if (n < 0) {
        mx_printchar('-');
        n = -n;
    }

    if (n >= 10) {  
        int next_digit = n / 10;
        mx_printint(next_digit);
    }

    mx_printchar((n % 10) + '0');
}
