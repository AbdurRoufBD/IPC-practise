#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int i,j;
    pid_t pid;
    for (i = 1; i <= 3; i++)            /*simple while loop, loops 3 times */
    {
        pid = fork();                   /*returns 0 if a child process is created */
        if(pid == 0){                   /*pid should be a 0 for first loop */
            printf("Hello!\n");         /*we print hello */
            return (i);                 /*will this return i to the parent process that called fork? */
        }   else {                      /*fork hasn't returned 0? */
            pid = wait(&j);             /*we wait until j is available? */

            printf("WIFEXITED :: %d\n",WIFEXITED(j));
            printf("Received %d :: pid : %d\n", WEXITSTATUS(j),pid);   /*if available we print "received (j)" */
        }
    }
}
