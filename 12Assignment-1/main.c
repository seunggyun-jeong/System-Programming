#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int status;
    printf("부모 프로세스 시작\n");

    if(fork() == 0) {
        execl("/bin/xsh",NULL);
        exit(1);
    }

    wait(&status);

    return 0;
}
