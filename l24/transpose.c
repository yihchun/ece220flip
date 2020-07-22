#include <stdio.h>

void transpose(const int *src, int *dst, int srow, int scol) {
  int i, j;
  for (i=0; i<srow; i++)
    for (j=0; j<scol; j++) {
      /* dst[j][i] = src[i][j]
       * src[i][j] = src[i*scol + j]
       * dst[j][i] = dst[j*srow + i]
       */
      dst[j*srow + i] = src[i*scol + j];
    }
}
      

int main() {
  int src[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  int dst[4][3];
  int i, j;

  transpose(&src[0][0], &dst[0][0], 3, 4);

  for (i=0; i<4; i++) {
    for (j=0; j<3; j++) {
      printf("%d ", dst[i][j]);
    }
    printf("\n");
  }
}
