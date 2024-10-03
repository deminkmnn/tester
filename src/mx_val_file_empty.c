#include "../inc/pathfinder.h"


int static get_file_length(const char *file) {
    if (!file){
        return -1;  
    }

    int length = 0;
    int file_descriptor = open(file, O_RDONLY);  

    if (file_descriptor < 0){
        return -1;  
    }

    char buffer[1];

    while (read(file_descriptor, buffer, sizeof(buffer)) > 0) {
        length++;
    }

    if (close(file_descriptor) < 0){
        return -1;
    }

    return length;
}


void mx_val_file_empty(t_main *main) {
    if (get_file_length(main->file->name) <= 0){  
        mx_printallerr(FILE_EMPTY, main->file->name); 
    }
}
