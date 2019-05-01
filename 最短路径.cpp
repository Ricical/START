/*119.最短路径 (15分) 
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
有5个城市(A,B,C,D,E),其中每个城市到其他城市的直达距离已知，两个城市之间只有一条公路。
计算从城市A到其他任意城市的最短路径距离。
输入描述
4行数据， 第一行是A到(B,C,D,E)的直达距离，第二行是B到（C,D,E）的直达距离，。。。，第4行
是D到E的直达距离。
输出描述
A城市到(B,C,D,E)的最短距离。
输入样例
2 3 4 5  
3 4 2 
4 3   
3
输出样例
2 3 4 4*/
#include <iostream>
#include <cstring>
using namespace std;

const int inf=1e9+9;
int dis[100],g[5][5];
bool v[100];

void dijkstra(){
	for(int i=1;i<=5;i++){
		dis[i]=inf;
	}
	dis[1]=0;
	memset(v,0,sizeof(v));
	for(int i=1;i<=5;i++){
		int mark=-1,mindis=inf;
		for(int j=1;j<=5;j++){
			if(!v[j]&&dis[j]<mindis){
				mindis=dis[j];
				mark=j;
			}
			v[mark]=1;
		}
		for(int j=1;j<=5;j++){
			if(!v[j]){
				dis[j]=min(dis[j],dis[mark]+g[mark][j]);
			}
		}
	}
}

int main(){
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			if(i==j){
				g[i][j]=0;
			}
			else if(j<i) g[i][j]=g[j][i]; 
			else cin>>g[i][j];
		}
	}
	dijkstra();
	for(int i=2;i<=5;i++){
		cout<<dis[i]<<' ';
	}
	return 0;
}
