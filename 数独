//java
class Solution {
    public void solveSudoku(char[][] board) {
        boolean[][] row = new boolean[9][9];
        boolean[][] col = new boolean[9][9];
        boolean[][] block = new boolean[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    row[i][num] = true;
                    col[j][num] = true;
                    block[i / 3 * 3 + j / 3][num] = true;
                }
            }
        }
        dfs(board, row, col, block, 0, 0);
    }

    private boolean dfs(char[][] board, boolean[][] row, boolean[][] col, boolean[][] block, int i, int j) {
        while (board[i][j] != '.') {
            if (++j >= 9) {
                i++;
                j = 0;
            }
            if (i >= 9) {
                return true;
            }
        }
        for (int num = 0; num < 9; num++) {
            int blockIndex = i / 3 * 3 + j / 3;
            if (!row[i][num] && !col[j][num] && !block[blockIndex][num]) {
                board[i][j] = (char) ('1' + num);
                row[i][num] = true;
                col[j][num] = true;
                block[blockIndex][num] = true;
                if (dfs(board, row, col, block, i, j)) {
                    return true;
                } else {
                    row[i][num] = false;
                    col[j][num] = false;
                    block[blockIndex][num] = false;
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }

    private void printBoard(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        char[][] board = new char[][]{
                {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
        };
        Solution solution = new Solution();
        solution.printBoard(board);
        solution.solveSudoku(board);
        System.out.println();
        solution.printBoard(board);
    }
}


//c
#include <stdio.h>
#define n 9
int a[n][n]= {
	0,0,5,3,0,0,0,0,0,
	8,0,0,0,0,0,0,2,0,
	0,7,0,0,1,0,5,0,0,
	4,0,0,0,0,5,3,0,0,
	0,1,0,0,7,0,0,0,6,
	0,0,3,2,0,0,0,8,0,
	0,6,0,5,0,0,0,0,9,
	0,0,4,0,0,0,0,3,0,
	0,0,0,0,0,9,7,0,0};

bool ok(int x, int y) { 
	int up, down, left, right;
	int i,j;

	up=x/3*3;
	down=up+3;

	left=y/3*3;
	right=left+3;

	for(i=0; i<9; i++) {
		if(a[x][y]==a[i][y] && i!=x && a[i][y]!=0)
			return false;
	}

	for(i=0; i<9; i++) {
		if (a[x][y]==a[x][i] && i!=y && a[x][i]!=0)
			return false;
	}

	for(i=up; i<down; i++) {
		for(j=left; j<right; j++)
			if(i!=x || j!=y) {
				if(a[i][j]==a[x][y] && a[i][j]!=0)
					return false;
			}
	}

	return true;
}
void traceback(int x,int y) { 
	if(a[x][y]!=0) {
		if(y==n-1) {
			if(x==n-1) {
				printf("=============\n");
				for (int i=0; i<9; i++) {
					for (int j =0; j <9; j++) {
						printf("%d ",a[i][j]);
					}
					printf("\n");
				}
			} else
				traceback(x+1,y);
		} else {
			if(x==n-1)
				traceback(0,y+1);
			else
				traceback(x+1,y);
		}
	} else {
		for(int i=1; i<10; i++) {
			a[x][y]=i;
			if(ok(x,y)) {
				if(y==n-1) {
					if(x==n-1) {
						for (int i=0; i<9; i++) {
							for (int j =0; j <9; j++) {
								printf("%d ",a[i][j]);
							}
							printf("\n");
						}
					} else
						traceback(x+1,y);
				} else {
					if(x==n-1)
						traceback(0,y+1);
					else
						traceback(x+1,y);
				}
			}
			a[x][y]=0;
		}

	}

}

int main() {
	traceback(0,0);
	return 0;
}
