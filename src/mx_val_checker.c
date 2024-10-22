#include "../inc/pathfinder.h"

bool mx_val_checker(t_main *main) {
    if (!main || !main->file) return false;

    // First, check if the file exists
    if (!mx_val_file_doesntexist(main)) return false;

    // Then, check if the file is empty
    if (!mx_val_file_empty(main)) return false;

    // Check if the file ends with a valid line break
    if (!mx_val_check_end_line(main->file->filearray)) return false;

    char **filearr = main->file->array;
    if (!filearr) return false;

    // Continue with other validation checks
    if (!mx_val_first_line(main)) return false;
    if (!mx_val_check_delim(filearr)) return false;
    if (!mx_val_check_island_one_isalpha(filearr)) return false;
    if (!mx_val_check_island_two_isalpha(filearr)) return false;
    if (!mx_val_check_number(filearr)) return false;
    if (!mx_val_check_duplicate_bridges(filearr)) return false;
    if (!mx_val_sum_of_bridges(main->path)) return false;
    if (!mx_check_duplicate_directions(main)) return false;

    return true;
}