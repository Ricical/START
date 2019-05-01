/*637.二分-跳过去 (10分)
C时间限制：1000 毫秒 |  C内存限制：3000 Kb
题目内容：
“跳过去”比赛将在一条河中进行，河中分布着一些大石头。组委会选择了两块石头作为
比赛起点和终点。在起点和终点之间，有 N 块石头（不含起点和终点的岩石）。
比赛时选手们将从起点出发，每一步跳向下一块石头，直到终点。
为了提高比赛难度，组委会计划移走一些石头，使得选手们在比赛过程中的最短跳跃距离
尽可能长。由于预算限制，组委会至多从起点和终点之间移走 M 块石头
（不能移走起点和终点的石头）。
输入描述
输入第一行包含3个整数 L,N，M，表示起点和终点的距离，之间的岩石数，
以及组委会至多移走的岩石数。接下来 N 行，每行一个整数，第 i 行的整数0<d[i]<L, 
表示中间依次的每块石头与起点的距离，保证d[i]<d[i+1]
其中L<=10^9, M<N-2<=10^5
输出描述
最短跳跃距离的最大值
输入样例
25 5 2
2
11
14
17
21
输出样例
4*/ 
#include <iostream>
using namespace std;

const int maxn=100009;
int high=0,low=0,L,n,m,d[maxn];

void solve(){
	high=L;
	while(low<=high){
		int mid=(low+high)>>1;
		int l=0,r=1,count=0;
		while(r<=n){
			if((d[r]-d[l])<mid){
				count++;
			}
			else{
				l=r;
			}
			r++;
		}
		if(count>m){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	cout<<high<<endl; 
}

int main(){
	cin>>L>>n>>m;
	d[0]=0,d[n+1]=L;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	solve();
	return 0;
} 
