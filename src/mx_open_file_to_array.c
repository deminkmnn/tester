#include "../inc/pathfinder.h"

char **mx_open_file_to_array(char *file) {
    // Read the entire file into a string
    char *filetoarr = mx_file_to_str(file);
    
    // Check if the file content could not be read or is empty
    if (!filetoarr) {
        return NULL;  // Return NULL if file could not be read or is empty
    }

    // Split the string into an array of strings (lines)
    char **array = mx_strsplit(filetoarr, '\n');
    
    // Free the original file content string as it's no longer needed
    mx_strdel(&filetoarr);
    
    // Check if the array is NULL (could happen if the file is empty or invalid)
    if (!array) {
        return NULL;  // Return NULL if there are no lines in the file
    }

    return array;
}
