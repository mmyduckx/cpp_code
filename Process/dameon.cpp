#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
#define MAXFILE 65535
using namespace std;
int main(){
    pid_t pid = fork(); //step 1
    string str = "this is a Dameon\n";
    if(pid < 0){
        cerr << "error fork" << endl;
        exit(1);
    }
    else if( pid > 0){
        exit(0);
    }
    else{ // child process
        setsid();       //step 2
        chdir("/");     //step 3
        umask(0);       //step 4
        for(int i = 0; i<MAXFILE; ++i){
            close(i);
        }
        
        int count = 1;
        while (1)
        {
            ofstream f_out("/tmp/dameon.log", ios::out | ios::app);
            if(f_out.good()){
                f_out << str << count++ << endl;
            }
            f_out.close();
            sleep(2);
        }
    }
        return 0;
}
