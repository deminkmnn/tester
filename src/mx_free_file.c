#include "../inc/pathfinder.h"

void mx_free_file(t_file *file) {
    if (!file) return;

    if (file->filearray) {
        free(file->filearray);
    }

    if (file->array) {
        mx_del_strarr(&file->array);
    }

    if (file->fd >= 0) {
        close(file->fd);
    }

    free(file);
}
