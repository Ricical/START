/*108.最长不降子序列 (15分) 
C时间限制：1 毫秒 |  C内存限制：3000 Kb
题目内容：
所谓子序列，就是在原序列里删掉若干个元素后剩下的序列，
以字符串"abcdefg"为例子，去掉bde得到子序列"acfg"现在的问题是，
给你一个数字序列，你要求出它最长的单调不降子序列。
输入描述
多组测试数据，每组测试数据第一行是n(1<=n<=10000)，表示n个数据，
下一行是n个比10^9小的正整数

输出描述
对于每组测试数据输出一行，每行内容是最长的单调不降子序列
的长度

输入样例
5
1 2 4 8 16
5
1 10 4 9 7
9
0 0 0 1 1 1 5 5 5

输出样例
5
3
9*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int inf=1e9+9;

int a[10000],dp[10000];

int main(){
	int n;
	while(cin>>n){
		int res=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			dp[i]=1;
			for(int j=0;j<i;j++){
				if(a[j]<=a[i]){
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
			res=max(res,dp[i]);
		}
		cout<<res<<endl;
	}
	return 0; 
}
