#include "../inc/pathfinder.h"

t_file *mx_open_file(char *argv[]) {

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return NULL;
    }


    t_file *file = malloc(sizeof(t_file));
    if (!file) {
        close(fd);  
        return NULL;
    }


    char **array = mx_open_file_to_array(argv[1]);
    if (!array) {
        close(fd);  
        free(file); 
        return NULL;
    }

    file->filearray = mx_file_to_str(argv[1]);
    if (!file->filearray) {
        close(fd);            
        mx_del_strarr(&array); 
        free(file);           
        return NULL;
    }

    file->name = argv[1];
    file->array = array;

    close(fd);

    return file;
}
