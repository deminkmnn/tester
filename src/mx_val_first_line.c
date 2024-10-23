#include "../inc/pathfinder.h"
#include <limits.h> // for INT_MAX

bool mx_isnumber(const char *s) {
    if (!s || *s == '\0') return false;
    if (s[0] == '0' && s[1] != '\0') return false; 
    for (int i = 0; s[i]; i++) {
        if (!mx_isdigit(s[i])) return false;
    }
    return true;
}

long long mx_parse_bridge_length(const char *line) {
    char **parts = mx_strsplit(line, '-');
    if (!parts || !parts[1]) {
        mx_del_strarr(&parts);
        return -1;
    }

    char **length_part = mx_strsplit(parts[1], ',');
    if (!length_part || !length_part[1] || !mx_isnumber(length_part[1])) {
        mx_del_strarr(&parts);
        mx_del_strarr(&length_part);
        return -1; 
    }


    long long bridge_length = mx_atoll(length_part[1]);


    mx_del_strarr(&parts);
    mx_del_strarr(&length_part);

    return bridge_length;
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

    long long count_island = mx_atoll(array[0]);

    if (count_island > INT_MAX || count_island <= 0) {
        mx_printallerr(INVALID_FIRST_LINE, NULL);
        mx_free_main(main);
        return false;
    }

    main->count_island = (int)count_island; 

    long long total_sum = 0;
    for (int i = 1; array[i] != NULL; i++) {  
        long long bridge_length = mx_parse_bridge_length(array[i]);

        if (bridge_length < 0) {
            mx_printallerr(INVALID_LINE, mx_itoa(i + 1)); 
            mx_free_main(main);
            return false;
        }

        total_sum += bridge_length;

        if (total_sum > INT_MAX) {
            mx_printallerr(SUM_OF_BRIDGES_TOO_BIG, NULL);  
            mx_free_main(main);
            return false;
        }
    }

    return true;
}
