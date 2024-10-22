#include "../inc/pathfinder.h"

bool mx_val_file_doesntexist(t_main *main) {
    // Open the file in read-only mode
    main->file->fd = open(main->file->name, O_RDONLY);
    
    // Check if the file cannot be opened (i.e., it doesn't exist)
    if (main->file->fd < 0) {
        mx_printallerr(FILE_DOESNTEXIST, main->file->name);
        return false;
    }

    // Check if the file is empty
    struct stat file_stat;
    if (fstat(main->file->fd, &file_stat) < 0) {
        close(main->file->fd);  // Always close the file descriptor after using it
        return false;           // Handle stat error
    }

    // If file size is 0, it is considered empty
    if (file_stat.st_size == 0) {
        close(main->file->fd);  // Close the file descriptor before returning
        mx_printallerr(FILE_EMPTY, main->file->name);  // Print error: file is empty
        return false;
    }

    // If the file exists and is not empty, close the file descriptor and return true
    close(main->file->fd);
    main->file->fd = -1;  // Reset the file descriptor after closing
    return true;
}
