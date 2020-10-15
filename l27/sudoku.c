#include <stdio.h>
#include <strings.h>

#define N 3
#define FORMAT "%d"

/* return -1 if invalid
 * return 0 if partial solution
 * return 1 if complete solution
 */
int check_sudoku(const int *arr) {
  int count[N*N+1];
  int i, j, k, l;

  /* row */
  for (i=0; i<N*N; i++) {
    bzero(count, sizeof(count));
    for (j=0; j<N*N; j++)
      if (arr[i*N*N+j] && count[arr[i*N*N+j]]++)
	return -1;
  }

  /* column */
  for (i=0; i<N*N; i++) {
    bzero(count, sizeof(count));
    for (j=0; j<N*N; j++)
      if (arr[j*N*N+i] && count[arr[j*N*N+i]]++)
	return -1;
  }

  for (i=0; i<N; i++) {
    for (j=0; j<N; j++) {
      bzero(count, sizeof(count));
      for (k=0; k<N; k++)
	for (l=0; l<N; l++)
	  if (arr[(i*N+k)*N*N+(j*N+l)] &&
	      count[arr[(i*N+k)*N*N+(j*N+l)]]++)
	    return -1;
    }
  }

  for (i=0; i<N*N*N*N; i++)
    if (!arr[i])
      return 0;

  return 1;
}

/* pass a partial solution so solve_sudoku. 
 * PRE: inputs must be valid (check_sudoku does not return -1)
 * returns 1 with a completed solution if solvable
 * returns 0 and does not modify array if not solvable
 */
int solve_sudoku(int *arr) {
  int i, j;
  for (i=0; i<N*N*N*N; i++)
    if (!arr[i])
      break;

  if (i == N*N*N*N)
    return 1;

  for (j=1; j<=N*N; j++) {
    arr[i] = j;
    if (check_sudoku(arr) == -1)
      continue;
    if (solve_sudoku(arr))
      return 1;
  }
  arr[i] = 0;
  return 0;
}

void show_board(const int *array) {
  int i, j;
  for (i=0; i<N*N; i++) {
    for (j=0; j<N*N; j++) {
      printf(FORMAT, array[i*N*N+j]);
    }
    printf("\n");
  }
}

#define Z 0,0,0
int board[N*N*N*N] = {0,0,5, 3,0,0, Z,
		      0,0,7, 0,0,4, Z,
		      1,0,6, 0,5,0, 0,2,0,
		      
		      4,0,0, 0,7,0, Z,
		      8,1,0, Z, 0,5,9,
		      Z, 0,3,0, 0,0,6,
		      
		      0,5,0, 0,8,0, 6,0,1,
		      Z, 1,0,0, 3,0,0,
		      Z, 0,0,9, 4,0,0};
int main() {
  solve_sudoku(board);
  show_board(board);
}
