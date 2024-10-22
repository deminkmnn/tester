#include "../inc/pathfinder.h"

void mx_stderr(const char *message) {
    if (message != NULL) {
        write(STDERR_FILENO, message, mx_strlen(message));
    }
}
