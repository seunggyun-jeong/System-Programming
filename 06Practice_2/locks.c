#include <fcntl.h>
#include <unistd.h>
/* TYPE
 * 1 : F_RDLCK (읽기 잠금)
 * 2 : F_UNLCK (잠금 해제)
 * 3 : F_WRLCK (쓰기 잠금)
 * */

/* WHENCE
 * 0 : SEEK_SET (파일 처음부터 시작)
 * 1 : SEEK_CUR (현재 포인터 부터 시작)
 * 2 : SEEK_END (파일 끝 부터 시작)
 */

int locks(int fd, int type, off_t offset, int whence, off_t len) {
    struct flock lock;

    // 잠금 관련 설정
    lock.l_type = type; // 파일 잠금 형식
    lock.l_whence = whence; // 기준 위치
    lock.l_start = offset; // 잠금 시작 위치
    lock.l_len = len; // 잠금 길이

    return fcntl(fd, F_SETLK, &lock); // 잠금 실행 성공 시 0, 실패 시 -1 반환

};

