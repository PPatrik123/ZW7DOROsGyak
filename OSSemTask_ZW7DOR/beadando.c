#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    int szulo_fd[2], gyerek_fds[2];
    int val = 0, gyerekpid = 0;



    pipe(szulo_fd);
    pipe(gyerek_fds);


    if (fork() != 0)
    {

        close(szulo_fd[0]);



        val = getpid();
        write(szulo_fd[1], &val, sizeof(val));
        close(szulo_fd[1]);
        printf("Szülõ(%d) pidje: %d\n",getpid(),val);
        read(gyerek_fds[0], &gyerekpid, sizeof(gyerekpid));
        printf("Gyerek(%d) elkuldte a pidjet : %d\n",getpid(),gyerekpid);
        wait(NULL);
        printf("A szülõ megvárta a gyereket\n");

                // close the write descriptor
        close(szulo_fd[1]);
    }
    else
    {
        close(gyerek_fds[0]);
        close(szulo_fd[1]);


        read(szulo_fd[0], &val, sizeof(val));

        printf("Gyerek(%d) ki írja a szülõtõl kapott pid-et: %d\n", getpid(), val);
        gyerekpid = getpid();
        write(gyerek_fds[1], &gyerekpid, sizeof(gyerekpid));




        close(szulo_fd[0]);
        exit(0);
    }
    return 0;
}
