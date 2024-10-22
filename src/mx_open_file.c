#include "../inc/pathfinder.h"

t_file *mx_open_file(char *argv[]) {
    // Open the file
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        return NULL;
    }

    // Allocate memory for t_file struct
    t_file *file = malloc(sizeof(t_file));
    if (!file) {
        close(fd);  // Close the file if allocation fails
        return NULL;
    }

    // Read the file into an array of strings (lines)
    char **array = mx_open_file_to_array(argv[1]);
    if (!array) {
        close(fd);  // Close the file
        free(file); // Free allocated memory for t_file struct
        return NULL;
    }

    // Read the entire file into a string
    file->filearray = mx_file_to_str(argv[1]);
    if (!file->filearray) {
        close(fd);            // Close the file descriptor
        mx_del_strarr(&array); // Free the array
        free(file);           // Free the file struct
        return NULL;
    }

    // Assign values to the t_file struct
    file->name = argv[1];
    file->array = array;
    
    // Close the file descriptor as it's no longer needed
    close(fd);

    return file;
}
