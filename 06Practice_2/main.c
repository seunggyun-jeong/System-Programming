#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"
#include "locks.h"

int main(int argc, char *argv[]) {
    int fd, id;
    struct student rec;
    struct flock lock;

    if(argc < 2) {
        fprintf(stderr, "사용법 : %s 파일\n", argv[0]);
        exit(1);
    }

    if((fd = open(argv[1], O_RDWR)) == -1) {
        perror(argv[1]);
        exit(2);
    }

    printf("\n검색할 학번 입력 : ");
    while(scanf("%d", &id) == 1) {
        if (locks(fd, F_RDLCK,(id - START_ID) * sizeof(rec), SEEK_SET, sizeof(rec)) == -1) {
            perror(argv[1]);
            exit(3);
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

        if (locks(fd, F_UNLCK,(id - START_ID) * sizeof(rec), SEEK_SET, sizeof(rec)) == 0) {
            printf("\nFile : %s, StdID : %d  잠금 해제 성공!\n", argv[1], id);
        }
        printf("\n검색할 학번 입력 : ");
    }

    close(fd);
    exit(0);

}
