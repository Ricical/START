/*326.0/1�������� (20��) 
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
��Ʒ����U=��u1,u2��un��������ֱ�Ϊs1,s2��..sn����ֵ�ֱ�Ϊv1,v2��.vn������C�ı���������㷨ʵ�ַ��뱳������Ʒ��ֵ���
��������
��һ��������Ʒ��n,�ڶ�������ÿ����Ʒ���������������ÿ����Ʒ�ļ�ֵ�����������뱳��������C
�������
�������ֵ����
��������
3
3 4 5
4 5 6
10
�������
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
