#include <stdlib.h>

char* env(char* var) {
  var = getenv(var);
  return var ? var : "";
}
