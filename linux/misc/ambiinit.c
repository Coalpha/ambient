// cd /mnt/c/ambient/linux/misc; gcc ambiinit.c -g3 -o /usr/bin/ambiinit && /usr/bin/ambiinit
#define _GNU_SOURCE
// #define DEBUG
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char* readfile(char* restrict file) {
  #ifdef DEBUG
    printf("readfile(%s) -> ", file);
  #endif
  FILE* fd = fopen(file, "r");
  if (!fd) {
    printf("Couln't read \"%s\": %s\n", file, strerror(errno));
    return NULL;
  }
  char* data = malloc(300);
  fgets(data, 300, fd);
  #ifdef DEBUG
    printf("\"%s\"\n", data);
  #endif
  return data;
}

char* concat(char* restrict s0, char* restrict s1) {
  int len = strlen(s0) + strlen(s1) + 1;
  char* out = malloc(len);
  strcpy(out, s0);
  strcat(out, s1);
  *(out + len) = 0;
  return out;
}

int main(int argc, char** argv) {
  (void) argc;
  *argv = "/bin/bash";
  #ifdef DEBUG
    puts("main started");
  #endif
  char* ambient = readfile("/etc/ambient");
  char* version = readfile("/proc/version");
  if (!ambient || !version) {
    return errno;
  }
  char* root = geteuid() ? "root=false" : "root=true";
  char* wsl = strstr(version, "Microsoft") ? "wsl=true" : "wsl=false";
  char* dotfiles = concat(ambient, "/linux");
  char* BASH_ENV = concat(dotfiles, "/main");
  free(version);
  char* envp[] = {
    concat("ambient=", ambient),
    concat("dotfiles=", dotfiles),
    concat("BASH_ENV=", BASH_ENV),
    "TERM=xterm-256color",
    "AMBIINIT=true",
    "LANG=C.UTF-8",
    root,
    wsl,
    0
  };
  execvpe(*argv, argv, envp);
  fprintf(stderr, "Couldn't execve \"%s\": %s\n", argv[0], strerror(errno));
  return errno;
}
