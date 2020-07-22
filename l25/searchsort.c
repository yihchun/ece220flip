#include <stdio.h>

int *linearsearch(int *haystack, int needle, int len) {
  int i;
  for (i=0; i<len; i++) {
    if (haystack[i] == needle)
      return haystack+i;
  }
  return NULL;
}

/* takes sortedarray, sorted in non-descending order */
int *binarysearch(int *sortedarray, int val, int len) {
  int left, right, mid;
  left = 0;
  right = len-1;
  while (left <= right) {
    mid = (left+right)/2;
    if (sortedarray[mid] == val) {
      return sortedarray+mid;
    } else if (sortedarray[mid] < val) {
      left = mid+1; /* go right */
    } else {
      right = mid-1; /* go left */
    }
  }
  return NULL;
}

void bubblesort(int *array, int len) {
  int i, j, tmp;
  for (i=0; i<len; i++) {
    for (j=1; j<(len-i); j++) {
      if (array[j-1] > array[j]) {
	tmp = array[j-1];
	array[j-1] = array[j];
	array[j] = tmp;
      }
    }
    /*
    for (j=0; j<len; j++)
      printf("%d ", array[j]);
    printf("\n");
    */
  }
}

void insertionsort(int *array, int len) {
  int i, j, tmp;
  for (i=1; i<len; i++) {
    /* PRE: 0..i-1 are sorted
     * POST: 0..i sorted
     * [ sorted ] array[i] [ ... ]
     */
    for (j=i; j; j--) {
      if (array[j-1] > array[j]) {
	tmp = array[j-1];
	array[j-1] = array[j];
	array[j] = tmp;
      }
    }
    for (j=0; j<len; j++)
      printf("%d ", array[j]);
    printf("\n");
  }
}

int main() {
  int x[] = {0,52,34,26,19,10,12,14,16,18,20};
  int y;
  int i;

  insertionsort(x, 11);
  /*
  for (i=0; i<11; i++) {
    printf("%d\n", x[i]);
  }
  */
  
  while (1) {
    scanf("%d", &y);
    printf("%p %p\n", linearsearch(x, y, 11), binarysearch(x, y, 11));
  }
}
