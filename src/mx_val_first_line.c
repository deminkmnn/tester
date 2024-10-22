#include "../inc/pathfinder.h"

static bool mx_isnumber(const char *s) {
    if (!s || *s == '\0') return false;
    if (s[0] == '0' && s[1] != '\0') return false;
    for (int i = 0; s[i]; i++) {
        if (!mx_isdigit(s[i])) return false;
    }
    return true;
}

bool mx_val_first_line(t_main *main) {
    if (!main || !main->file || !main->file->array) {
        mx_free_main(main);
        return false;
    }
    char **array = main->file->array;
    if (!mx_isnumber(array[0])) {
        mx_printallerr(INVALID_FIRST_LINE, NULL);
        mx_free_main(main);
        return false;
    }
    main->count_island = mx_atoi(array[0]);
    return true;
}
