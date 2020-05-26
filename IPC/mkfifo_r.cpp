#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define P_FIFO "/tmp/p_fifo"

int main(int argc, char **argv){
    char cache[100];
    int fd;
    memset(cache, 0, sizeof(cache));
    if(access(P_FIFO,F_OK) == 0){
        execlp("rm", "-f", P_FIFO, NULL);
        printf("access..\n");
    }
    if(mkfifo(P_FIFO, 0777) < 0){
        printf("mkfifo failed\n");
    }
    fd = open(P_FIFO, O_RDONLY| O_NONBLOCK);
    while (1){
        memset(cache, 0, sizeof(cache));

        if((read(fd, cache, 100)) == 0){ // no data to read
            printf("no data. \n");
        }
        else{
            printf("get data:%s\n", cache);
        }
        sleep(2);
    }
    close(fd);
    return 0;
}