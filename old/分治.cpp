#include<iostream>
using namespace std;
/**************定义查找硬币的函数find_false()**********************/
int find_false(int a[],int low,int high)
{
	int i=0;						//作为遍历的计数器 
	int re=0;						//re作为返回值
	int sum1,sum2,sum3;			//三个用来累加的变量
	sum1=sum2=sum3=0;
	if(low+1==high)				//当遍历到最后两个元素的时候 
	{
		if(a[low]<a[high])
		{
			re=low;
			return re;
		}
		else
		{
			re=high;
			return re;
		}
	} 
	if((high-low+1)%2==0)				//当长度为偶数的时候
	{
		for(i=low;i<=low+(high-low+1)/2-1;i++)	//对前半段求和 
		{
			sum1+=a[i];
		}
		for(i=low+(high-low+1)/2;i<=high;i++)	//对后半段求和 
		{
			sum2+=a[i];
		}
		if(sum1<sum2)				//假币在前半段 
		{
			re=find_false(a,low,low+(high-low+1)/2-1);
			return re;
		}
		else if(sum2<sum1)			//假币在后半段 
		{
			re=find_false(a,low+(high-low+1)/2,high);
			return re;	
		}	
	}
	else						//当长度为奇数的时候 
	{
		for(i=low;i<=low+(high-low)/2-1;i++)	//对前半段求和
		{
			sum1+=a[i];
		}
		for(i=low+(high-low)/2+1;i<=high;i++)//对后半段求和
		{
			sum2+=a[i];
		}
		sum3=a[low+(high-low)/2];			//sum3用于存放中间数据 
		if(sum1<sum2)					//假币在前半段 
		{
			re=find_false(a,low,low+(high-low)/2-1);
			return re; 
		}
		else if(sum2>sum1)
		{
			re=find_false(a,low+(high-low)/2,high);
			return re;
		}
		else if(sum1+sum3==sum2+sum3)	//中间的那个就是假币！
		{
			re=(high-low)/2+1;
			return re;
		} 
	} 
} 
int main()
{
	int a[100];
	int n,i,re;
	cout<<"请输入硬币的个数：";
	cin>>n;
	cout<<"请分别输入这个"<<n<<"个硬币的重量："<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	re=find_false(a,1,n);
	cout<<"假币是第"<<re<<"硬币"<<endl;
	return 0;	
}
