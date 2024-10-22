#include "../inc/pathfinder.h"

void mx_val_checker(t_main *main) {
    char **filearr = NULL;

    mx_val_file_doesntexist(main);
    mx_val_file_empty(main);
    mx_val_check_end_line(main->file->filearray);

    filearr = main->file->array;

    mx_val_first_line(main);
    mx_val_check_delim(filearr);
    mx_val_check_island_one_isalpha(filearr);
    mx_val_check_island_two_isalpha(filearr);
    mx_val_check_number(filearr);


}

