#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    pid_t ppid, pid, cpid;
    ppid = getpid();
    printf("Szulo PID: %d\n", ppid);
    
    pid = fork();
    if (pid < 0) {
        printf("Fork hiba");
        return 1;
    } else if (pid == 0) {
        cpid = getpid();
        printf("Gyermek PID: %d\n", cpid);
        execl("./eyzwg9_child", "eyzwg9_child", (char *)NULL);
        printf("Execl hiba");
        return 1;
    } else {
        int status;
        if (waitpid(pid, &status, 0) == -1) {
            printf("Waitpid hiba");
            return 1;
        }
        printf("A gyermek futasa befejezodott, visszateresi ertek: %d\n", status);
        return 0;
    }
}
