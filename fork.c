#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
    pid_t child_pid;

    child_pid = fork ();

    if (child_pid == 0) 
        printf ("This is the child process, with id %d\n", (int) getpid());
    else {
        printf ("This is the parent process with id %d\n", (int) getpid ());
        printf ("The child's process ID is %d\n", (int) child_pid);
    }
        

    return 0;

}