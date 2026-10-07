#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 256

int main() {
    char input[MAX_INPUT];
    printf("shell$ ");
    while (fgets(input, MAX_INPUT, stdin) != NULL) {
        input[strcspn(input, "\n")] = '\0';
        if (strlen(input) == 0) {
            printf("shell$ ");
            continue;
        }
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork failed");
            exit(1);
        }
        if (pid == 0) {
            char *args[] = { input, NULL };
            execvp(input, args);
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
        printf("shell$ ");
    }
    return 0;
}