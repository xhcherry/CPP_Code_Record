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
