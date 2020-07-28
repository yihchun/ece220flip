#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentStruct {
  char *NAME;
  int UIN;
  float GPA;
} student;

int main() {
  int i;
  student *arr = malloc(200 * sizeof(student));
  student *tmp;
  if (!arr) {
    fprintf(stderr, "Could not allocate array\n");
    return 1;
  }
  for (i=0; i<200; i++) {
    arr[i].NAME = malloc(100);
    if (!arr[i].NAME) {
      fprintf(stderr, "Could not allocate name for student %d\n", i);
      return 1;
    }
    strcpy(arr[i].NAME, "To be set");
    arr[i].UIN = -1;
    arr[i].GPA = 0;
  }

  tmp = realloc(arr, 400*sizeof(student));
  if (!tmp) {
    fprintf(stderr, "Could not allocate bigger array\n");
    return 1;
  }

  for (i=200; i<400; i++) {
    arr[i].NAME = malloc(100);
    if (!arr[i].NAME) {
      fprintf(stderr, "Could not allocate name for student %d\n", i);
      return 1;
    }
    strcpy(arr[i].NAME, "To be set");
    arr[i].UIN = -1;
    arr[i].GPA = 0;
  }
  
  for (i=0; i<400; i++) {
    free(arr[i].NAME);
  }
  free(arr);
  return 0;
}
