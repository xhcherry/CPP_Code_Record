#include<iostream>
using namespace std;
/**************�������Ӳ�ҵĺ���find_false()**********************/
int find_false(int a[],int low,int high)
{
	int i=0;						//��Ϊ�����ļ����� 
	int re=0;						//re��Ϊ����ֵ
	int sum1,sum2,sum3;			//���������ۼӵı���
	sum1=sum2=sum3=0;
	if(low+1==high)				//���������������Ԫ�ص�ʱ�� 
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
	if((high-low+1)%2==0)				//������Ϊż����ʱ��
	{
		for(i=low;i<=low+(high-low+1)/2-1;i++)	//��ǰ������ 
		{
			sum1+=a[i];
		}
		for(i=low+(high-low+1)/2;i<=high;i++)	//�Ժ������ 
		{
			sum2+=a[i];
		}
		if(sum1<sum2)				//�ٱ���ǰ��� 
		{
			re=find_false(a,low,low+(high-low+1)/2-1);
			return re;
		}
		else if(sum2<sum1)			//�ٱ��ں��� 
		{
			re=find_false(a,low+(high-low+1)/2,high);
			return re;	
		}	
	}
	else						//������Ϊ������ʱ�� 
	{
		for(i=low;i<=low+(high-low)/2-1;i++)	//��ǰ������
		{
			sum1+=a[i];
		}
		for(i=low+(high-low)/2+1;i<=high;i++)//�Ժ������
		{
			sum2+=a[i];
		}
		sum3=a[low+(high-low)/2];			//sum3���ڴ���м����� 
		if(sum1<sum2)					//�ٱ���ǰ��� 
		{
			re=find_false(a,low,low+(high-low)/2-1);
			return re; 
		}
		else if(sum2>sum1)
		{
			re=find_false(a,low+(high-low)/2,high);
			return re;
		}
		else if(sum1+sum3==sum2+sum3)	//�м���Ǹ����Ǽٱң�
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
	cout<<"������Ӳ�ҵĸ�����";
	cin>>n;
	cout<<"��ֱ��������"<<n<<"��Ӳ�ҵ�������"<<endl;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	re=find_false(a,1,n);
	cout<<"�ٱ��ǵ�"<<re<<"Ӳ��"<<endl;
	return 0;	
}
