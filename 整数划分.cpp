/*91.�������� (15��) 
Cʱ�����ƣ�2 ���� |  C�ڴ����ƣ�65535 Kb
��Ŀ���ݣ�
����һ��������n�Ļ��֣����ǰ�n���һϵ��������֮�͵ı��ʽ��ע�⣬�ֻ���˳���޹أ�����6=5+1��6=1+5��
ͬһ�ַֻ������⣬���������������Ҳ��һ�ַֻ���
���磺����������n=5�����Ի���Ϊ��
1+1+1+1+1
1+1+1+2
1+1+3
1+2+2
2+3
1+4
5
��������
����һ��������n

�������
���n�������ֵ�����k

��������
5

�������
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
