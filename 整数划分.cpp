/*91.整数划分 (15分) 
C时间限制：2 毫秒 |  C内存限制：65535 Kb
题目内容：
对于一个正整数n的划分，就是把n变成一系列正整数之和的表达式。注意，分划与顺序无关，例如6=5+1跟6=1+5是
同一种分划。另外，单独这个整数本身也算一种分划。
例如：对于正整数n=5，可以划分为：
1+1+1+1+1
1+1+1+2
1+1+3
1+2+2
2+3
1+4
5
输入描述
输入一个正整数n

输出描述
输出n整数划分的总数k

输入样例
5

输出样例
7*/
#include <iostream>
#include <cstring>
using namespace std;

const int maxn=1000;
const int maxnn=1000000009;
int n,dp[maxn][maxn];

void solve(){
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j-i>=0){
				dp[i][j]=(dp[i-1][j]+dp[i][j-i])%maxnn;
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	int sum=0;
	cout<<dp[n][n]<<endl;
}
int main(){
	cin>>n;
	memset(dp,0,sizeof(dp));
	solve();
	return 0;
} 
