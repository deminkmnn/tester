#include "../inc/pathfinder.h"

bool mx_val_cmd_args(int argc) {
    if (argc != 2) {
        mx_printallerr(INVALID_CMD_ARGS, NULL);
        return false;
    }
    return true;
}
