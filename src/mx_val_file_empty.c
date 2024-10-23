#include "../inc/pathfinder.h"

bool mx_val_file_empty(t_main *main) {
    if (main->file->fd < 0) return false;

    struct stat file_stat;
    if (fstat(main->file->fd, &file_stat) < 0) {
        close(main->file->fd);
        return false;
    }

    if (file_stat.st_size == 0) {
        close(main->file->fd);  
        mx_printallerr(FILE_EMPTY, main->file->name);  
        return false;
    }

    close(main->file->fd);
    return true;
}
