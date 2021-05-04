#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12

int semID;
int nsems;
int semnum;
int r;
int semflag;
int cmd;

struct sembuf sembuf, *sop;
union semun;

int main()
{
    int arg;
	nsems = 1;
	semflag = 00666 | IPC_CREAT;
	semID = semget (SEMKEY, nsems, semflag);
	if (semID < 0 ) {
        perror("Probl�ma/hiba!\n");
        return 0;}
	else
        printf("Az ID avagy azonos�t�: %d\n",semID);
	printf ("K�rem a semval �rt�ket: ");

	semnum = 0;
	cmd = SETVAL;
	scanf("%d", &arg);
	r = semctl(semID, semnum, cmd, arg);
	printf("\nVisszat�r�si �rt�k: %d , semval �rt�k: %d\n",r, arg);

    return 0;

}
