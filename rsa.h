#ifndef _RSA_H_
#define _RSA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define S_BUFFER 2000
#define VALUE 1000

/* factors.c */
void init(char *buffer);
void file2buffer(char *filename, char *buffer);
long long unsigned int _atoi(char *src, long long unsigned int *dest);
void _putint(long long unsigned int *dest, long long unsigned int n);

/* pollard-rho.c */
long long unsigned int modular_pow(long long unsigned int base, int exponent, long long unsigned int modulus);
long long unsigned int __gcd(long long unsigned int a, long long unsigned int b);
long long unsigned int PollardRho(long long unsigned int n);
long long unsigned int compute(long long unsigned int *src, long long unsigned int n);

#endif /* _RSA_H */
