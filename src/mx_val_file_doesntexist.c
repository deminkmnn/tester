#include "../inc/pathfinder.h"


void mx_val_file_doesntexist(t_main *main) {
    int fd = main->file->fd;

    if (fd < 0){
        mx_printallerr(FILE_DOESNTEXIST, main->file->name);
    }
}
