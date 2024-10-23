#include "../inc/pathfinder.h"

void mx_free_file(t_file *file) {
    if (!file) return;

    if (file->filearray) {
        free(file->filearray);
        file->filearray = NULL;
    }

    if (file->array) {
        mx_del_strarr(&file->array);
        file->array = NULL;
    }

    if (file->fd >= 0) {
        close(file->fd);
    }

    free(file);
    file = NULL;
}
