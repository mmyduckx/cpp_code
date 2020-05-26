#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;
int main(){
    pid_t pid = fork();
    if(pid< 0){
        cout << "Failed to fork" <<endl;
    }
    else if(pid > 0){
        cout << "Parent process, sleep for 20 s" << endl;
        pid_t pr = wait(NULL);
        // sleep(20);
        cout << "catched a child process with pid:" << pr << endl;

        cout << "After sleep, exit!" << endl;
    }
    else{
        cout << "Child process , exit!" << endl;
        exit(0);
    }
    return 0;
}

