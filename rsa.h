#ifndef _RSA_H_
#define _RSA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define S_BUFFER 2000
#define VALUE 1000

/* factors.c */
void init(char *buffer);
void file2buffer(char *filename, char *buffer);
int _atoi(char *src, int *dest);
void _putint(int *dest, int n);

#endif /* _RSA_H */
