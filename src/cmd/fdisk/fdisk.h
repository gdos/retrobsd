#ifndef _FDISK_H
#define _FDISK_H

#define A_NONE 0
#define A_PRINT 1
#define A_DELETE 2
#define A_NEW 3
#define A_ACTIVE 4
#define A_TYPE 5

struct chs {
    unsigned char   head;
    struct {
        unsigned    cylhigh : 2;
        unsigned    sector : 6;
    } __attribute__((packed));
    unsigned char   cyllow;
}__attribute__((packed));

struct partition {
#define P_ACTIVE    0x80
    unsigned char   status;
    struct chs      start;
    unsigned char   type;
    struct chs      end;
    unsigned long   lbastart;
    unsigned long   lbalength;
};

struct mbr {
    unsigned char   bootstrap1[218];
    unsigned short  pad0000;
    unsigned char   biosdrive;
    unsigned char   secs;
    unsigned char   mins;
    unsigned char   hours;
    unsigned char   bootstrap2[216];
    unsigned int    sig;
    unsigned short  pad0001;
    struct partition partitions[4];
    unsigned short  bootsig;
}__attribute__((packed));

#endif
