#include<stdio.h> 
#include <stdlib.h>
void SelectSort(int num[],int n)
{
    for(int i = 0; i < n; i++)
    {
        int min = i;
        for(int j = i + 1; j <= n; j++)
        {
            if(num[min] > num[j])
                min = j;
        }
        if(min != i)
        {
            int temp = num[min];
            for(int q = min- 1;q >= i; q--)
			num[q + 1] = num[q];
            num[i] = temp;

        }
    }
}

int main() 
{
	int num[1024],n;
	printf("????????????????????");
	scanf("%d",&n);
	printf("\n???????????????§µ?\n");
	for (int i = 1; i <= n; i++)
		scanf("%d",&num[i]);
	printf("\n??¨¹?????????????????\n");
	SelectSort(num,n);
	for(int i = 1; i <= n; i++)
		printf("%d\t",num[i]);
	printf("\n");
	system("pause");
	return 0;
}

