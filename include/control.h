#include <stdbool.h>

#ifndef _CONTROL_A_H
#define _CONTROL_A_H
  typedef struct {
    bool escaped;
    char* data;
  } control_result;
  control_result* cesc(char it);
  control_result** sesc(char* it);
#endif
