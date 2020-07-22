#include <stdio.h>

unsigned int stringlen(const char *s) {
  int ret = 0;
  while (*(s++)) {
    ret++;
  }
  return ret;
  
  /*
  for (ret = 0; s[ret] != '\0'; ret++)
    ;
  return ret;
  */
}

void stringcopy(const char *src, char *dst, unsigned int limit) {
  int i;
  for (i=0; (i<(limit-1)) && src[i]; i++)
    dst[i] = src[i];
  dst[i] = '\0';
}

int main() {
  char dstarray[20];
  printf("String length is %d\n", stringlen("hello world"));
  stringcopy("hello world", dstarray, 20);
  printf("%s\n", dstarray);
}
