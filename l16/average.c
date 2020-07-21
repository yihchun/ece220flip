#include <stdio.h>

/* average takes an array and a number of elements and computes the average.
 * if the number of elements is 0, average returns 0 and prints an error 
 * message.
 */
int average(int *arr, unsigned int count) {
  int accum = 0;
  int i;
  if (!count) {
    printf("You tried to take the average of an empty array\n");
    return 0;
  }
  for (i=0; i<count; i++)
    accum += arr[i];
  return accum/count;
}

int main() {
  int arr[50];
  int i;
  printf("Enter some number of integers to average. Finish with a -1 (not included)\n");
  for (i=0; i<50; i++) {
    scanf("%d", arr+i); /* &arr[i] */
    if (arr[i] == -1)
      break;
  }
  printf("Average is %d\n", average(arr, i));
  return 0;
}
