#include <stdio.h>
#ifdef __GLIBC__
#include <gnu/libc-version.h>
#endif

// https://stackoverflow.com/questions/9705660/check-glibc-version-for-a-particular-gcc-compiler

int main(void) {
#ifdef __GLIBC__
  printf("\nGNU libc compile-time version: %u.%u\n", __GLIBC__,
         __GLIBC_MINOR__);
  printf("GNU libc runtime version:      %s\n\n", gnu_get_libc_version());
  return 0;
#else
  puts("Not the GNU C Library");
  return 1;
#endif
}
