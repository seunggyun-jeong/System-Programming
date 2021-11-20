#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXARG 10

int main() {
    int i;
    int status;
    char input[100];
    char *args[MAXARG];
    char *ptr;
    char *nextptr;

    printf("[%d] 부모 프로세스 시작\n",getpid());
    while(1) {
        i = 1;
        printf("Plz Input Cmd : ");
        gets(input);

        ptr = strtok_r(input, " ", &nextptr);
        args[0] = ptr;
        while (ptr) {
            ptr = strtok_r(NULL, " ", &nextptr);
            args[i] = ptr;
            i++;
        }

        if (fork() == 0) {
            printf("[%d] 자식 프로세스 시작\n", getpid());
            execvp(args[0], &args[0]);
            exit(1);
        }
        printf("[%d] 자식프로세스 종료 \n", wait(&status));

        if(status == 256) {
            break;
        }
        printf("SUCCESS\n");
    }

    printf("[%d] 부모 프로세스 종료\n", getpid());

    return 0;
}
