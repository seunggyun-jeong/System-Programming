#include <stdio.h>
#define MAXLINE 80

int main(int argc, char *argv[]) {
    FILE *fp;

    int line = 0;
    char buffer[MAXLINE];

    char c;
    int i = 1;
    int flag = 0;

    if(argv[1][0] == '-') {
        flag = 1;
        i++;
    }


    while(argv[i] != NULL){
        fp = fopen(argv[i], "r");

        while(fgets(buffer, MAXLINE, fp) != NULL) {
            line++;
            if(flag == 1){
                printf("%3d %s", line, buffer);
            }
            else {
                printf("%s", buffer);
            }

        }
        printf("\n");
        line = 0;

        fclose(fp);

        i++;
    }


    return 0;
}
