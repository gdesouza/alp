#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigusr1_count = 0;

void handler (int signal_number)
{
    ++sigusr1_count;
}

void schlaft( time_t delay )
{
    time_t timer0, timer1;
    time (&timer0);
    do
    {
        time (&timer1);
    } 
    while ((timer1 - timer0) < delay);
}

int main ()
{
    struct sigaction sa;
    memset (&sa, 0, sizeof(sa));
    sa.sa_handler = &handler;
    sigaction (SIGUSR1, &sa, NULL);

    /* print the process id */
    printf ("This is the parent process with id %d\n", (int) getpid ());

    /* Do some lengthy stuff here */
    schlaft ((time_t)10);

    printf ("SIGUSR was raised %d times\n", sigusr1_count);
    return 0;
}