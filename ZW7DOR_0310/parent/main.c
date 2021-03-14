#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    pid_t pidnum;
    pidnum = fork();
    if(pidnum == 0) { execl("./child.out", "child", NULL); }
    else { perror("Nem szulo processz"); }
    return 0;
}
