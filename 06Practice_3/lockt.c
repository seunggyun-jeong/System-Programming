#include <fcntl.h>
#include <unistd.h>

pid_t lockt(int fd, int type, off_t offset, int whence, off_t len) {
    struct flock lock;

    // 잠금 관련 설정
    lock.l_type = type; // 파일 잠금 형식
    lock.l_whence = whence; // 기준 위치
    lock.l_start = offset; // 잠금 시작 위치
    lock.l_len = len; // 잠금 길이
    lock.l_pid = getpid(); //pid 지정

    // 잠금 실행
    if(fcntl(fd, F_SETLK, &lock) == -1 ) {
        // 잠금이 실패 되었다면 잠금되었는지 검사 후 pid 리턴
        fcntl(fd, F_GETLK, &lock);
        return lock.l_pid;
    }
    else {
        //잠금 성공 시 0 리턴
        return 0;
    }
}