/*119.���·�� (15��) 
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
��5������(A,B,C,D,E),����ÿ�����е��������е�ֱ�������֪����������֮��ֻ��һ����·��
����ӳ���A������������е����·�����롣
��������
4�����ݣ� ��һ����A��(B,C,D,E)��ֱ����룬�ڶ�����B����C,D,E����ֱ����룬����������4��
��D��E��ֱ����롣
�������
A���е�(B,C,D,E)����̾��롣
��������
2 3 4 5  
3 4 2 
4 3   
3
�������
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
