#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

#define MAXLINE 4096
// using namespace std;

int main(int argc, char** argv){
    int listen_fd, client_socket;
    struct sockaddr_in serv_addr;
    char buff[4096];
    int n;

    //create socket
    if( (listen_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        std::cerr << "Create socket error: " << strerror(errno) << std::endl;
        return 0;
    }
    //set server_addr
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(6666);

    //bind socket
    if( bind(listen_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1 ){
       std::cerr << "Bind socket error: " << strerror(errno) << std:: endl;
       return 0;
    }
    //listen socket
    if(listen(listen_fd, 10) == -1){  //2nd parameter is SOMAXCONN in the queue
        std::cerr << "Listen socket error: " << strerror(errno) << std::endl;
        return 0;
    }

    printf("======waiting for client's request======\n");
    while (1)
    {   // wait for a connection
        if( (client_socket = accept(listen_fd, (struct sockaddr*)NULL, NULL) ) == -1 ){
            std::cerr << "Aceept socket error: "<< strerror(errno) << std::endl;
            continue;
        }
        int bytesReceived = recv(client_socket, buff, MAXLINE, 0);
        buff[bytesReceived] = '\0';
        printf("recv msg from client: %s\n", buff);
        close(client_socket);
    }
    close(listen_fd);
    return 0;
}
