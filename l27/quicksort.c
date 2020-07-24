#include <stdio.h>
void show_array(const int *array, int len) {
  int i;
  for (i=0; i<len; i++)
    printf("%d ", array[i]);
  printf("\n");
}


/* sorts the len elements or array[0..len-1] in ascending order */
void quicksort(int *array, int len) {
  int partition, left, right, tmp;
  if (len <= 1) return;
  partition = array[0];
  left = 1;
  right = len-1;
  while (left <= right) {
    while (left <= right && array[left] <= partition) left++;
    while (left <= right && array[right] >= partition) right--;
    if (left > right) break;
    tmp = array[left];
    array[left] = array[right];
    array[right] = tmp;
  }
  /* we know left = right+1 */
  /* partition [ 1.. right ] [ left .. len-1 ] */
  array[0] = array[right];
  array[right] = partition;

  /* [0.. right-1] partition [left .. len-1] */
  if (right > 1)
    quicksort(array, right);

  if (left < len-1)
    quicksort(array + left, len-left);
}

#define LEN 16

int main() {
  FILE *fp = fopen("/dev/urandom", "r"); /* don't worry about this line */
  int myarr[LEN];
  int i;

  for (i=0; i<LEN; i++)
    myarr[i] = fgetc(fp); /* don't worry about this line */

  show_array(myarr, LEN);
  quicksort(myarr, LEN);
  show_array(myarr, LEN);
}  
  
