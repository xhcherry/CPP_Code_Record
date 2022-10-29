#include <stdio.h>

int f(unsigned int n)
{
    int result;
    switch(n)
    {
        case 1:
            result = 7;
            break;
        case 2:
            result = 3;
            break;            
        default:
            result = f(n - 1) + f(n - 2);
            break;    
    }
    return result;
}
int mian()
{
	int n = 9;
	printf("%d",f(n,7));
 } 
