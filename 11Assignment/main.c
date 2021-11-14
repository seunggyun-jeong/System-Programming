#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {

    char **ptr;
    extern char **environ;

    if(argc < 2) {
        fprintf(stderr, "사용방법 : %s 명령어", argv[0]);
        exit(1);
    }

    if(argv[1][0] == '-') {
        switch (argv[1][1]) {
            case 'e' :
                if(argc == 3) {
                    ptr = getenv(argv[2]);
                    printf("%s = %s \n",argv[2], ptr);
                }
                else {
                    for(ptr=environ; *ptr != 0; ptr++) {
                        printf("%s \n", *ptr);
                    }
                }
                break;
            case 'u' :
                printf("실제 사용자 ID : %d(%s) \n",getuid(),getpwuid(getuid())->pw_name);
                printf("유효 사용자 ID : %d(%s) \n",geteuid(),getpwuid(geteuid())->pw_name);
                break;
            case 'g' :
               printf("실제 그룹 ID : %d(%s) \n",getgid(),getgrgid(getgid())->gr_name);
               printf("유효 그룹 ID : %d(%s) \n",getegid(),getgrgid(getegid())->gr_name);
                break;
            case 'i' :
                printf("프로세스 ID : [%d] \n",getpid());
                break;
            case 'p' :
                printf("부모 프로세스 ID : [%d] \n",getppid());
                break;
            default:
                printf("잘못된 입력입니다.");
        }
    }


    return 0;
}
