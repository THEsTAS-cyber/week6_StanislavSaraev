#include <stdio.h>
#include <time.h>
#include <sys/wait.h>

int main()
{
    int first_id;
    first_id = fork();
    clock_t t1 = clock();
    if (first_id == 0) {
        printf("Hello from child process %d, my parent process is %d\n", getpid(), getppid());
        clock_t t = clock() - t1;
        printf("Time taken by child process %d: %f seconds\n", getpid(), ((float)t)/CLOCKS_PER_SEC);
    }
    else {
        int second_id;
        second_id = fork();
        clock_t t2;
        if (second_id == 0) {
            printf("Hello from child process %d, my parent process is %d\n", getpid(), getppid());
            clock_t t = clock() - t2;
            printf("Time taken by child process %d: %f seconds\n", getpid(), ((float)t)/CLOCKS_PER_SEC);
        }
        else{
            printf("Hello from parent process %d, my parent process is %d\n", getpid(), getppid());
            wait(NULL);
            wait(NULL);
            clock_t t = clock() - t1;
            printf("Time taken by parent process %d: %f seconds\n", getpid(), ((float)t)/CLOCKS_PER_SEC);
        }
    }
}