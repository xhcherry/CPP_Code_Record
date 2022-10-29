#include<stdio.h>
#include<stdlib.h>
int arr[50][50];
void arrayFill(int n, int i, int j, int floor,int sum) {
	int i_inner = i, j_inner = j,k;
	if(floor == 0)
		return;
	if((n & 1 == 1) && floor == 1) {
		arr[i_inner][j_inner] = sum++;
	} else {
		for(k = 0; k < 4; k++) {
			if(k == 0) {
				for(; j_inner < j + n - 1; j_inner++)
					arr[i_inner][j_inner] = sum++;
			} else if(k == 1) {
				for(; i_inner < i + n - 1; i_inner++)
					arr[i_inner][j_inner] = sum++;
			} else if(k == 2) {
				for(; j_inner > j; j_inner--)
					arr[i_inner][j_inner] = sum++;
			} else if(k == 3) {
				for(; i_inner > i; i_inner--)
					arr[i_inner][j_inner] = sum++;
			}
		}
	}
	arrayFill(n-=2,++i,++j,--floor,sum);
}
int main() {
	int n,i,j;
	while(scanf("%d",&n) != EOF) {
		arrayFill(n,0,0,(n+1)/2,1);
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				printf("%d\t",arr[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
