#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#define SEM_KEY 4001
#define SHM_KEY 5678
union semun {
    int val;
};
int main(void){
        /*创建共享内存*/
    int shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT|0666);
    if(shmid < 0){
        printf("create shm error\n");
        return -1;
    }
    void * shmptr;
    shmptr = shmat(shmid, NULL, 0);
    if(shmptr == (void *) -1){
        printf("shmat error:%s\n", strerror(errno));
        return -1;
    }  
    int* data = (int *)shmptr;
    int semid = semget(SEM_KEY, 2, 0666);//创建一个semid,并且有两个信号量
    struct sembuf sembuf1;
    union semun semun1;
    while(1){
        sembuf1.sem_num = 1; //指向第二个信号量,其val = 1
        sembuf1.sem_op = -1; //初值为1,-1后不会阻塞
        sembuf1.sem_flg = SEM_UNDO;
        semop(semid, &sembuf1, 1);
        scanf("%d", data); //等待用户输入
        sembuf1.sem_num = 0; //对第一个信号量操作,使reader不再阻塞
        sembuf1.sem_op = 1;
        sembuf1.sem_flg = SEM_UNDO;
        semop(semid, &sembuf1, 1);
    }
    return 0;
}