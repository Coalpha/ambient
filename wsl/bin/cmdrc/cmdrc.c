#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
  printf("%d", argc);
  char* system32 = getenv("system32");
  puts(system32);
  // printf("argc: %d\n", argc);
  // for (register int i = 0; i < argc; i++) {
  //   printf("argv[%d] = %s\n", i, *(argv + i));
  // }
}
