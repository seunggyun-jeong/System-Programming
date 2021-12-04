#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

struct sigaction newact;
struct sigaction oldact;

// signal 함수와 똑같이 동작하는 mySignal 함수 구현
void mySignal(int signo, void (*func)()) {
    newact.sa_handler = *func;     // sigaction 구조체에 함수 등록
    sigfillset(&newact.sa_mask);   // 다른 시그널을 차단하도록 마스크 설정

    sigaction(signo, &newact, &oldact);    // 입력되는 signo의 처리 액션을 새로 지정
}

void intHandler(int signo) {
    printf("인터럽트 시그널 처리\n");
    printf("시그널 번호: %d\n", signo);
    exit(0);
}

int main() {
    mySignal(SIGINT, intHandler);

    while(1) {
        sleep(1);
        printf("Ctrl + C를 눌러보세요.\n");
    }
    printf("실행되지 않음");
}
