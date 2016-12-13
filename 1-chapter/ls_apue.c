#include "apue.h"
#include <dirent.h>

int main (int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    char *dir_name = argv[1];

    if (argc != 2) {
        err_quit("usage: ls dir_name");
    }

    if ((dp = opendir(dir_name)) == NULL) {
        err_sys("can't open %s", dir_name);
    }

    while ((dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}
