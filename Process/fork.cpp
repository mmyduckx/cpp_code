#include <iostream>
#include <unistd.h>

int global = 1;
int main(){
    pid_t pid;
    int stack = 1;
    int* heap = new int(3);
    pid = fork();
    if(pid < 0){
        std::cerr << "fail to fork" << std::endl;
        exit(-1);
    }
    else if(pid == 0){
        //child process
        ++global;
        ++stack;
        (*heap)++;
        std::cout << "In sub-process, global:"<< global << " stack:" << stack << " heap:" << *heap << std::endl;
    }
    else{
        //parent process
        sleep(2);
        std::cout << "Parent-process, global:"<< global << " stack:" << stack << " heap:" << *heap << std::endl;
    }
    return 0;
}