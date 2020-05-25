#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAXLINE 4096

int main(int argc, char** argv){
    int sock_fd, n;
    char recvline[4096], sendline[4096];
    struct sockaddr_in serv_addr;

    if( argc != 2){
        printf("usage: ./client <ipaddress>\n");
        return 0;
    }

    //create socket
    if( (sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }

    //set serv_addr
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6666);
    if( inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0){
        printf("inet_pton error for %s\n", argv[1]);
        return 0;
    }
    //connect to server
    if( connect(sock_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
        printf("connect error: %s(error: %d)\n", strerror(errno), errno);
        return 0;
    }

    printf("send msg to server: \n");
    //send
    fgets(sendline, 4096, stdin);
    if( send(sock_fd, sendline, strlen(sendline), 0) < 0){
        printf("send msg error: %s(errno: %d)\n", strerror(errno), errno);
        return 0;
    }
    close(sock_fd);
    return 0;
}