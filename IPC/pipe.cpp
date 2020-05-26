#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    // First pipe to send input string from parent
    // Second pipe to send concatenated string from child 
    int fd1[2]; // Used to store two ends of first pipe 
    int fd2[2]; // Used to store two ends of second pipe 

    char fixed_str[] = " with fixed str!";
    char input_str[100];
    pid_t pid;
    if(pipe(fd1) == -1){
        fprintf(stderr,"pipe failed");
        return 1;
    }
    if(pipe(fd2) == -1){
        fprintf(stderr,"pipe failed");
        return 1;
    }
    scanf("%s", input_str);
    pid = fork();
    if(pid < 0){
        fprintf(stderr,"fork failed");
        return 1;
    }
    else if(pid == 0){
        //parent process
        close(fd1[0]);

        // write input to child process
        write(fd1[1], input_str, strlen(input_str)+1);
        close(fd1[1]);

        //wait for child process to send string
        wait(NULL);

        close(fd2[1]);
        char concat_str[100];
        read(fd2[0], concat_str, 100);
        printf("Concatenated str: %s\n", concat_str);
        close(fd2[0]);

    }
    else{
        close(fd1[1]);

        char concat_str[100];
        read(fd1[0], concat_str, 100);
        int k = strlen(concat_str);
        for(int i = 0; i < strlen(fixed_str); ++i){
            concat_str[k++] = fixed_str[i];
        }
        
        concat_str[k] = '\0';
        close(fd1[0]);
        close(fd2[0]);
        write(fd2[1], concat_str, strlen(concat_str) + 1);
        close(fd2[1]);
        
        exit(0);
    }


}