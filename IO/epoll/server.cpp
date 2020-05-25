#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/types.h>

#define IPADDRESS "127.0.0.1"
#define PORT 6666
#define MAXSIZE 1024
#define LISTENQ 5
#define FDSIZE 1000
#define EPOLLEVENTS 100

/*declarations*/
//create socket and bind
int socket_bind(const char* ip, int port);
//IO epoll
void do_epoll(int listenfd);
//handle events
void handle_events(int epollfd, struct epoll_event* event, int num, int listenfd, char *buf);
//handle accept connection
void handle_accept(int epollfd, int listenfd);

void do_read(int epollfd, int fd, char* buf);
void do_write(int epollfd, int fd, char* buf);
void add_event(int epollfd, int fd, int state);
void modify_event(int epollfd, int fd, int state);
void delete_event(int epollfd, int fd, int state);

int main(int argc, char* argv[]){
    int listenfd;
    listenfd = socket_bind(IPADDRESS, PORT);
    listen(listenfd, LISTENQ);
    do_epoll(listenfd);
    return 0;
}

int socket_bind(const char* ip, int port){
    int listenfd;
    struct sockaddr_in servaddr;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd == -1){
        perror("socket error");
        exit(1);
    }
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &servaddr.sin_addr);
    servaddr.sin_port = htons(port);
    if(bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind error");
        exit(1);
    }
    return listenfd;
}

void do_epoll(int listenfd){
    int epollfd;
    struct epoll_event events[EPOLLEVENTS];
    int ret;
    char buf[MAXSIZE];
    memset(buf, 0, MAXSIZE);
    epollfd = epoll_create(FDSIZE);
    add_event(epollfd, listenfd, EPOLLIN);
    while(1){
        ret = epoll_wait(epollfd, events, EPOLLEVENTS, -1);
        handle_events(epollfd, events, ret, listenfd, buf);
    }
    close(epollfd);
}

void handle_events(int epollfd, struct epoll_event* events, int num, int listenfd, char* buf) {
    for(int i = 0; i < num; ++i) {
        int fd = events[i].data.fd;
        if((fd == listenfd) && (events[i].events & EPOLLIN)){
            handle_accept(epollfd, listenfd);
        }
        else if(events[i].events & EPOLLIN){
            do_read(epollfd, fd, buf);
        }
        else if(events[i].events & EPOLLOUT){
            do_write(epollfd, fd, buf);
        }
    }
}

void handle_accept(int epollfd, int listenfd){
    int clientfd;
    struct sockaddr_in clientaddr;
    socklen_t clientaddrlen;
    clientfd = accept(listenfd, (struct sockaddr*)&clientaddr, &clientaddrlen);
    if(clientfd == -1){
        perror("accpet error");
    }
    else{
        printf("accept a new client: %s:%d\n",inet_ntoa(clientaddr.sin_addr), clientaddr.sin_port);
        add_event(epollfd, clientfd, EPOLLIN);
    }
}

void do_read(int epollfd, int fd, char* buf){
    int n_read = read(fd, buf, MAXSIZE);
    if(n_read == -1){
        perror("read error");
        close(fd);
        delete_event(epollfd, fd, EPOLLIN);
    }
    else if(n_read == 0){
        fprintf(stderr, "client close.");
        close(fd);
        delete_event(epollfd, fd, EPOLLIN);
    }
    else{
        printf("read msg: %s", buf);
        modify_event(epollfd, fd, EPOLLOUT);
    }
}

void do_write(int epollfd, int fd, char* buf){
    int n_write = write(fd, buf, strlen(buf));
    if(n_write == -1){
        perror("write error");
        close(fd);
        delete_event(epollfd, fd, EPOLLOUT);
    }
    else{
        modify_event(epollfd, fd, EPOLLIN);
    }
    memset(buf, 0, MAXSIZE);
}

void add_event(int epollfd, int fd, int state) {
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
}

void delete_event(int epollfd, int fd, int state) {
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &ev);
}

void modify_event(int epollfd, int fd, int state) {
    struct epoll_event ev;
    ev.events = state;
    ev.data.fd = fd;
    epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &ev);
}

