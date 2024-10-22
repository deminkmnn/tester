#include "../inc/libmx.h"

int number_length(int number) {
    int length = 0;
    if (number <= 0) {
        length = 1; 
    }
    while (number != 0) {
        length++;
        number /= 10;
    }
    return length;
}

char *mx_itoa(int number) {
    int length = number_length(number);
    char *result = mx_strnew(length);

    if (result == NULL) {
        return NULL;
    }

    if (number == 0) {
        return mx_strcpy(result, "0");
    }

    if (number == -2147483648) {
        return mx_strcpy(result, "-2147483648");
    }

    bool is_negative = false;

    if (number < 0) {
        is_negative = true;
        number = -number;
    }

    for (int i = 0; i < length; i++) {
        result[i] = (number % 10) + '0';
        number /= 10;
    }

    if (is_negative) {
        result[length - 1] = '-';
    }

    mx_str_reverse(result);

    return result;
}
