#include <gnu/libc-version.h>
#include <stdio.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/9705660/check-glibc-version-for-a-particular-gcc-compiler

int main() { printf("\nGNU libc version: %s\n\n", gnu_get_libc_version()); }
