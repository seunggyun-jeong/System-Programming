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

    for(int i = 3; i >= 0; i--){
        printf("%s", savedText[i]);
    }

    close(fd);

    return 0;
}