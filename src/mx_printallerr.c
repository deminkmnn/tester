#include "../inc/pathfinder.h"

static void file_doesntexist(const char *s) {
    mx_printerr("error: file ");
    mx_printerr(s);
    mx_printerr(" does not exist\n");
}

static void file_empty(const char *s) {
    mx_printerr("error: file ");
    mx_printerr(s);
    mx_printerr(" is empty\n");
}

static void invalid_line(const char *s) {
    mx_printerr("error: line ");
    mx_printerr(s);
    mx_printerr(" is not valid\n");
}

void mx_printallerr(t_error err, const char *s) {
    if (err == INVALID_CMD_ARGS) {
        mx_printerr("usage: ./pathfinder [filename]\n");
    } else if (err == FILE_DOESNTEXIST) {
        file_doesntexist(s);
    } else if (err == FILE_EMPTY) {
        file_empty(s);
    } else if (err == INVALID_FIRST_LINE) {
        mx_printerr("error: line 1 is not valid\n");
    } else if (err == INVALID_LINE) {
        invalid_line(s);
    } else if (err == INVALID_NUM_ISLANDS) {
        mx_printerr("error: invalid number of islands\n");
    } else if (err == MEMORY_ALLOCATION_ERROR) {
        mx_printerr("error: memory allocation failed\n");
    }
    exit(1);
}
