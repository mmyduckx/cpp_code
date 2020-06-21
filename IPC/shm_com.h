#ifndef _SHMCOM_H_HEADER
#define _SHMCOM_H_HEADER
#define TEXT_SZ 2048
struct shared_use_st {
    int wrriten;
    char text[TEXT_SZ];
};
#endif