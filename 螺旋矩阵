#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
int m,n;
int main(){
    m = 5;
    n = 6;
    int maritx[m+1][n+1] = {0};
    int now = 1;
    int U = 1,D = m,L = 1,R = n;
    int i = 1,j = 1;
    while(now <= m*n){
        while(now <= m*n && j < R){
            maritx[i][j] = now++;
            j++;
        }
        while(now <= m*n && i < D){
            maritx[i][j] = now++;
            i++;
        }
        while(now <= m*n && j > L){
            maritx[i][j] = now++;
            j--;
        }
        while(now <= m*n && i > U){
            maritx[i][j] = now++;
            i--;
        }
        U++,D--,L++,R--;
        i++,j++;
        if(now == m*n) {
            maritx[i][j] = now++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            printf("%d\t",maritx[i][j]);
        }
        printf("\n");
    }
    return 0;
}


//分治
#include<stdio.h>
#include<stdlib.h>
int arr[50][50];
void arrayFill(int n, int i, int j, int floor,int sum) {
	int i_inner = i, j_inner = j;
	if(floor == 0)
		return;
	if((n & 1 == 1) && floor == 1) {
		arr[i_inner][j_inner] = sum++;
	} else {
		for(int k = 0; k < 4; k++) {
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
	int n;
	while(scanf("%d",&n) != EOF) {
		arrayFill(n,0,0,(n+1)/2,1);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				printf("%d\t",arr[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
