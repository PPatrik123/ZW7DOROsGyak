#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 0x12

int semID;
int nsems;
int r;
int semflag;
unsigned nsops;

struct sembuf sembuf, *sop;

int main()
{
	nsems = 1;
	semflag = 00666 | IPC_CREAT;
	semID = semget (SEMKEY, nsems, semflag);
	if (semID < 0 ){
        perror("Probl�ma/hiba!\n");
        return 0;
    }
	else
        printf("ID avagy azonos�t�: %d\n",semID);

	nsops = 1;
	sembuf.sem_flg = 0666;
	sembuf.sem_op = 1;
	sembuf.sem_num = 0;
	sop = &sembuf;
	r = semop(semID, sop, nsops);
	printf("Visszat�r�si �rt�k: %d\n",r);

    return 0;

}
