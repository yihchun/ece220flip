#include <stdio.h>

/* Takes a partial solution to N-Queens (board[i*n+j] is 0 if the [i][j] square
 * is empty, and 1 if it has queen), and completes the solution if possible.
 * PRE: The partial solution MUST include a queen per row in the first row rows
 *          (that is, rows 0..row-1).
 *      The partial solution MUST NOT contain any queens at row row or later.
 *      The partial solution must be legal (i.e., no queens can attack 
 *          each other)
 * POST: Returns 1 and completes the board if the solution is possible
 *       Returns 0 and does not change the board if no solution is possible
 */
int nqueens(int *board, int n, int row) {
  int col, i, legal;
  if (n == row) return 1;

  for (col = 0; col < n; col++) {
    /* check if row, col is a legal place to position a queen */
    /* we know that no queens are on this row due to precondition.
     * also know that no queens are below this row (precondition).
     * Check straight up and two diags going up
     */
    legal = 1;
    for (i=0; i<row; i++)
      if (board[i*n+col])
	legal = 0;
    if (!legal) continue;
    for (i=1; i <= row; i++)
      if (((col >= i) && board[(row-i)*n+(col-i)]) || /* up and left */
	  ((col+i < n) && board[(row-i)*n+(col+i)])) /* up and right */
	legal = 0;
    if (!legal) continue;
    board[row*n+col] = 1;
    if (nqueens(board, n, row+1))
      return 1; /* found our solution, return accordingly */
    /* recursive call didn't modify the board */
    board[row*n+col] = 0;
  }

  /* reached the end of the row, no place to put a queen */
  return 0;
}

void board_printer(const int *board, int n) {
  int i,j;
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) {
      printf("%c", board[i*n+j] ? 'Q' : '-');
    }
    printf("\n");
  }
}

#define N 8
int board[N*N];

int main() {
  board_printer(board, N);
  nqueens(board, N, 0);
  board_printer(board, N);
  return 0;
}
  
