#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "lockt.h"

int main(int argc, char *argv[]) {
    int fd, id;
    struct student rec;
    struct flock lock;
    int wait;
    int pid;
    char YesNo;
    if(argc < 2) {
        fprintf(stderr, "사용법 : %s 파일\n", argv[0]);
        exit(1);
    }

    if((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }
    printf("이 프로그램의 프로세스 번호 : %d\n\n", getpid());
    printf("\n검색할 학번 입력 : ");
    while(scanf("%d", &id) == 1) {
        getchar();
        if ((pid = lockt(fd, F_WRLCK,(id - START_ID) * sizeof(rec), SEEK_SET, sizeof(rec))) != 0) {
            printf("\n잠금되어있는 레코드 접근입니다.\n사용하고 있는 프로세스 번호 : %d\n", pid);
            printf("다른 레코드에 접근하시겠습니까? (y/n)");

            scanf("%c", &YesNo);

            if(YesNo == 'y' || YesNo == 'Y') {
                printf("\n검색할 학번 입력 : ");
                continue;
            }
            else{
                perror(argv[1]);
                exit(3);
            }
        }
        else {
            printf("File : %s, StdID : %d 파일 잠금 성공!\n\n", argv[1], id);
        }

        lseek(fd, (id-START_ID) * sizeof(rec), SEEK_SET);
        if((read(fd, &rec, sizeof(rec)) > 0) && (rec.id != 0)) {
            printf("이름 : %s\t 학번 : %d\t 점수 : %d\n", rec.name, rec.id, rec.score);
        }
        else {
            printf("레코드 없음!\n");
        }

        printf("계속 하려면 아무 키나 입력...");
        scanf("%d", &wait);

        if (lockt(fd, F_UNLCK,(id - START_ID) * sizeof(rec), SEEK_SET, sizeof(rec)) == 0) {
            printf("\nFile : %s, StdID : %d  잠금 해제 성공!\n", argv[1], id);
        }
        printf("\n검색할 학번 입력 : ");
    }

    close(fd);
    exit(0);

}
