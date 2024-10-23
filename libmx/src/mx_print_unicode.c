#include "../inc/libmx.h"


void mx_print_unicode(wchar_t c) {
    char bytes[4];  
    int bytes_to_write = 0;

    if (c < 0x80) {
        bytes[0] = (char)(c & 0x7F);
        bytes_to_write = 1;
    } 

    else if (c < 0x0800) {
        bytes[0] = (char)((c >> 6) & 0x1F) | 0xC0;
        bytes[1] = (char)(c & 0x3F) | 0x80;
        bytes_to_write = 2;
    } 

    else if (c < 0x010000) {
        bytes[0] = (char)((c >> 12) & 0x0F) | 0xE0;
        bytes[1] = (char)((c >> 6) & 0x3F) | 0x80;
        bytes[2] = (char)(c & 0x3F) | 0x80;
        bytes_to_write = 3;
    } 
    
    else if (c < 0x110000) {
        bytes[0] = (char)((c >> 18) & 0x07) | 0xF0;
        bytes[1] = (char)((c >> 12) & 0x3F) | 0x80;
        bytes[2] = (char)((c >> 6) & 0x3F) | 0x80;
        bytes[3] = (char)(c & 0x3F) | 0x80;
        bytes_to_write = 4;
    }

    write(1, bytes, bytes_to_write);
}

