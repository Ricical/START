/*326.0/1背包问题 (20分) 
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
物品集合U=｛u1,u2…un｝，体积分别为s1,s2…..sn，价值分别为v1,v2….vn；容量C的背包。设计算法实现放入背包的物品价值最大。
输入描述
第一行输入物品数n,第二行输入每个物品体积，第三行输入每个物品的价值，第四行输入背包的容量C
输出描述
输出最大价值数。
输入样例
3
3 4 5
4 5 6
10
输出样例
11*/

#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;

const int maxn=1e4+9;
int w[maxn],v[maxn];
int n,c;
int d[maxn][maxn];
bool x[maxn];

void FillD(){
	for(int i=0;i<=c;i++){
		d[0][i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			if(j<w[i]) d[i][j]=d[i-1][j];
			else d[i][j]=max(d[i-1][j],d[i-1][j-w[i]]+v[i]);
		}
	}
}

int OptLoad(){
	int i=n,j=c;
	while(i>=0){
		if(d[i][j]==d[i-1][j]){
			x[i]=0;
		}
		else{
			x[i]=1;
			j-=w[i];
		}
		i--;
	}
//	return d[n][c];
}
int main(){
	int ans;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	FillD();
	OptLoad();
	cout<<d[n][c]<<endl;
	for(int i=1;i<=n;i++){
		cout<<x[i]<<' ';
	} 
	return 0;
}
