/*108.����������� (15��) 
Cʱ�����ƣ�1 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
��ν�����У�������ԭ������ɾ�����ɸ�Ԫ�غ�ʣ�µ����У�
���ַ���"abcdefg"Ϊ���ӣ�ȥ��bde�õ�������"acfg"���ڵ������ǣ�
����һ���������У���Ҫ�������ĵ������������С�
��������
����������ݣ�ÿ��������ݵ�һ����n(1<=n<=10000)����ʾn�����ݣ�
��һ����n����10^9С��������

�������
����ÿ������������һ�У�ÿ����������ĵ�������������
�ĳ���

��������
5
1 2 4 8 16
5
1 10 4 9 7
9
0 0 0 1 1 1 5 5 5

�������
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
