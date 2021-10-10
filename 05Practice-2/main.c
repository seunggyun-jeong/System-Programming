#include <stdio.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char type(mode_t);
char *perm(mode_t);
void printStat(char*, char*, struct stat*);

int main(int argc, char *argv[]) {
    DIR *dp;
    char *dir;
    struct stat st;
    struct dirent *d;
    char path[BUFSIZ + 1];

    dir = ".";

    if((dp = opendir(dir)) == NULL){
        perror(dir);
    }

    while ((d = readdir(dp)) != NULL) {
        sprintf(path, "%s/%s", dir, d->d_name);

        // 파일의 상태 정보를 가져와서 st구조체에 저장
        if (lstat(path, &st) < 0 ) { //파일을 정상적으로 불러오지 못할 경우
            perror(path);
        }
        else if (argc == 1) { // 옵션 인자 지정이 없을 경우 (파일 이름만 출력)
            printf("%s\n", d->d_name);
        }
        else if(argv[1][0] == '-') { //옵션이 있을 때
            if (argv[1][1] == 'p') { //옵션이 p일 때 (디렉터리 파일일 경우 /를 붙임)
                if(S_ISDIR(st.st_mode)) {
                    printf("%s/\n", d->d_name);
                }
                else {
                    printf("%s\n", d->d_name);
                }
            }
            else if (argv[1][1] == 'a') { //옵션이 al일 때 (파일의 모든 상세정보 출력)
                if (argv[1][2] == 'l') {
                    printStat(path, d->d_name, &st);
                }

            }
            else if (argv[1][1] == 'i') { //옵션이 i일 때
                printf("%d %s \n", st.st_ino, d->d_name);
            }
            else if (argv[1][1] == 'Q') { //Q 옵션일 경우 파일, 디렉터리를 ""(쌍따옴표)안에 출력
                printf("\"%s\"\n", d->d_name);
            }
        }
    }

    closedir(dp);

    exit(0);

}

void printStat(char *pathname, char *file, struct stat *st) {
    printf("%5d", st->st_blocks);
    printf(" %c%s", type(st->st_mode), perm(st->st_mode));
    printf("%3d", st->st_nlink);
    printf(" %s %s", getpwuid(st->st_uid)->pw_name, getgrgid(st->st_gid)->gr_name);
    printf("%9d", st->st_size);
    printf("%.12s", ctime(&st->st_mtime) + 4);
    printf(" %s\n", file);
}

char type(mode_t mode) {
    if (S_ISREG(mode)) {
        return('-');
    }
    else if (S_ISDIR(mode)){
        return('d');
    }
    else if (S_ISCHR(mode)) {
        return('c');
    }
    else if (S_ISBLK(mode)) {
        return('b');
    }
    else if (S_ISLNK(mode)) {
        return('l');
    }
    else if (S_ISFIFO(mode)) {
        return('p');
    }
    else if (S_ISSOCK(mode)) {
        return('s');
    }
}

char *perm(mode_t mode) {
    int i;
    static char perms[10]="----------";

    for(i=0; i < 3; i++) {
        if (mode & (S_IREAD >> i*3)){
            perms[i*3] ='r';
        }
        if (mode & (S_IWRITE >> i*3)) {
            perms[i*3 + 1] ='w';
        }
        if (mode & (S_IEXEC >> i*3)) {
            perms[i*3 + 2] = 'x';
        }
    }
    return(perms);
}