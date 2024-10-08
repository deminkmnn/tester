#include "../inc/pathfinder.h"


t_file *mx_open_file(char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    t_file *file = malloc(sizeof(t_file));
    char **array = mx_open_file_to_array(argv[1]);

    file->name = argv[1];
    file->fd = fd;
    file->filearray = mx_file_to_str(argv[1]);
    file->array = array;
    return file;
}
