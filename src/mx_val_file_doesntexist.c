#include "../inc/pathfinder.h"

bool mx_val_file_doesntexist(t_main *main) {
    main->file->fd = open(main->file->name, O_RDONLY);
    

    if (main->file->fd == -1) {
        mx_printallerr(FILE_DOESNTEXIST, main->file->name);
        return false;
    }


    return true;
}
