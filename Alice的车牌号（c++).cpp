/*题目描述
Alice是NFS的死忠。一天，Alice想给自己游戏中的兰博基尼换个新车牌。NFS会随机生成一个由小写英文字母与数字组成的6位的车牌号给Alice，
但是Alice是个很迷信的人，如果车牌中包含13这个数字，她就会放弃这个车牌号，否者她会接受这个新的车牌号，那么现在请写个程序以判断Alice是否会接受游戏生成给她的新车牌。
输入
输入数据第一行有一个整数T，表示用T组测试数据。
对于每组测试数据，每行都会有一个长度为6的字符串，表示生成的车牌号。保证字符串仅由数字和小写英文字母组成。
输出
对于每组测试数据，输出占一行，首先应当输出一行“Case #k: ”，k表示第k组测试数据，然后对于每组测试数据，如果Alice接受这个车牌，输出“Yes, I like it!”，否则，输出“No, it's terrible!”。
*/


#include<bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	int k=0;
	while(T--) {
		k++;
		int flag=1;
		string s;
		cin>>s;
		int i;
		for(i=0; i<s.size()-1; i++) {
			if(s[i]=='1' and s[i+1]=='3') {
				flag=0;
				cout<<"Case #"<<k<<": No, it's terrible!"<<endl;
			}
		}
		if(i==s.size()-1 and flag==1) {
			cout<<"Case #"<<k<<": Yes, I like it!"<<endl;
		}
	}
	return 0;
}
