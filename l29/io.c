#include <stdio.h>

int main() {
  FILE *fin, *fout;
  fin = fopen("in_matrix.txt", "r");

  if (!fin) {
    fprintf(stderr, "Could not open in_matrix.txt\n");
    return 1;
  }
  
  fout = fopen("out_matrix.txt", "w");
  if (!fout) {
    fprintf(stderr, "Could not open out_matrix.txt\n");
    return 1;
  }

  int row, col, i, j;
  fscanf(fin, "%d %d", &row, &col);
  int matrix[row][col];

  for (i=0; i<row; i++)
    for (j=0; j<col; j++)
      fscanf(fin, "%d", &matrix[i][j]);

  fprintf(fout, "%d %d\n", col, row);
  for (i=0; i<col; i++) {
    for (j=0; j<row; j++) {
      fprintf(fout, "%d ", matrix[j][i]);
    }
    fprintf(fout, "\n");
  }

  fclose(fin);
  fclose(fout);
}
