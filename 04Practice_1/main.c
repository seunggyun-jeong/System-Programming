#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
    int fd;
    char savedText[10][100];
    char buf[BUFFSIZE];
    int line_count = 0;

    int file_row = 0;
    int file_column = 0;
    int n;

    char select_num[10];

    //파일 읽어들이기
    if((fd = open(argv[1], O_RDWR)) == -1 ) {
        printf("파일 오픈 실패");
    }
    else {
        printf("File read success\n");
    }

    //파일의 문자열 \n 단위로 끊어서 배열에 저장
    while ((n = read(fd, buf, 1)) > 0) {
        savedText[file_row][file_column] = buf[0];

        file_column++;

        if(buf[0] == '\n') {
            savedText[file_row][file_column] = '\0'; //문자열의 끝을 알리는 \0 입력
            file_row++;
            file_column = 0;
            line_count++;
        }
    }
    printf("Total Line : %d\n", line_count);

    printf("Pls 'Enter' the line to select : ");

    scanf("%s", select_num);

    //입력 형태에 따른 결과 값 출력
    if(select_num[0] == '*') {
        printf("%s", savedText[0]);
        printf("%s", savedText[1]);
        printf("%s", savedText[2]);
        printf("%s", savedText[3]);
    }
    else if(select_num[1] == '-' && ((int)select_num[0] - 48) > 0 && ((int)select_num[2] - 48) > 0) {
        for(int i = ((int)select_num[0] - 48) - 1; i < ((int)select_num[2] - 48); i ++) {
            printf("%s", savedText[i]);
        }
    }
    else if (select_num[1] == ',') {
        for(int i = 0; i <= 6; i+=2 ) {
            switch ((int)select_num[i] - 48) {
                case 1 :
                    printf("%s", savedText[0]);
                    break;
                case 2 :
                    printf("%s", savedText[1]);
                    break;
                case 3 :
                    printf("%s", savedText[2]);
                    break;
                case 4 :
                    printf("%s", savedText[3]);
                    break;
            }
        }
    }
    else if(4 >= atoi(select_num) > 0) {
        printf("%s", savedText[(int)select_num[0] - 48 - 1]);
    }
    else {
        printf("잘못된 입력입니다.");
    }


    close(fd);

    return 0;
}
