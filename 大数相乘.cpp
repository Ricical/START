/*117.������� (20��) 
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
һ�����ͱ���ֻ������������С��n!��ֵ���� n �ϴ�ʱ���ɽ��׳�ֵ�е�ÿһ������
����һ��һά�����һ��Ԫ���С�ʹ���ⷽ������ӡn!��ֵ��
��������
����n
�������
n!��ֵ
��������
18
�������
6402373705728000*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#define ll long long
using namespace std;

//'1','2','3','4','5','6','7'
const int maxn=1e7+9;
char a[maxn]={'1'},b[maxn]={'1'},c[maxn]={'1'};

void solve(){
	int i,j,m,n;
  	long sum,carry;
  	m = strlen(a)-1;
  	n = strlen(b)-1;
 	for(i=m;i>=0;i--)
    	a[i] -= '0';
 	for(i=n;i >=0;i--)
    	b[i] -='0';
//  	c[m+n+2] ='/0';
 	carry =0;
 	for(i=m+n;i>=0;i--){
   		sum=carry;
   		if((j=(i-m))<0)
    		j=0;
   		for(;j<=i&& j <=n;j++)
       		sum += (a[i-j]*b[j]);
   		c[i+1] = sum %10 + '0'; /*�������������*/
   		carry = sum/10;//��λ 
 	}
 	if((c[0]=carry+'0')=='0')
   		c[0] = '/040'; /* space */
   	strcpy(a,c);
}

int main(){
	ll n;
	cin>>n;
//	solve();
//	puts(c);
	for(ll i=2;i<=n;i++){
		sprintf(b,"%d",i);
		solve();
		memset(c,0,sizeof(c));
	}
	ll cnt=0;
	for(ll i=0;i<strlen(a);i++){
		if(a[i]!='0'){
			cnt=i;
			break;
		}
	}
	for(ll i=cnt;i<strlen(a);i++){
		cout<<a[i];
	}
}
