#include "apue.h"
#include <sys/wait.h>

int main(void) {
    //MAXLINE is 4096 from apue.h
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");

    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0; /*replace newline with null*/ 
        }

        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            // this is child process.
            execlp(buf, buf, (char *)0);
            err_ret("could not exec: %s", buf);
            exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0) {
            err_sys("waitpid error");
        }

        printf("%% ");
    }

    exit(0);
}
