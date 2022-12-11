/*
** PROJECT, 2022
** kern_syscall.c
** File description:
** Lib syscall's
*/

#include "kern_syscall.h"

// SYSCALL
unsigned long long int sys(register unsigned int syscall_nb,
register unsigned int fd, char *buffer, register unsigned int len)
{
    register int rax asm("rax") = syscall_nb;
    register int rdi asm("rdi") = fd;
    register char* rsi asm("rsi") = buffer;
    register int rdx asm("rdx") = len;
    asm("syscall");
    return rax;
}

void sys_exit(int status)
{
    register int rax asm("rax") = 60;
    register int rdi asm("rdi") = status;
    asm("syscall");
    return;
}

unsigned long long int sys_write(register unsigned int fd, char *buff, int len)
{
    if (len == 1)
        len = 1;
    else
        while(buff[++len]);
    register int rax asm("rax") = 1;
    register int rdi asm("rdi") = fd;
    register char* rsi asm("rsi") = buff;
    register int rdx asm("rdx") = len;
    asm("syscall");
    return rax;
}

unsigned long long int sys_read(register unsigned int fd, void *buff,
long long unsigned int len)
{
    register int rax asm("rax") = 0;
    register int rdi asm("rdi") = fd;
    register char* rsi asm("rsi") = buff;
    register int rdx asm("rdx") = len;
    asm("syscall");
    return rax;
}

long long int sys_open(char *path, int flags, int mode)
{
    register int rax asm("rax") = 2;
    register char* rdi asm("rdi") = path;
    register int rsi asm("rsi") = flags;
    register int rdx asm("rdx") = mode;
    asm("syscall");
    return rax;
}

int sys_close(int fd)
{
    register int rax asm("rax") = 3;
    register unsigned int rdi asm("rdi") = fd;
    asm("syscall");
    return rax;
}
