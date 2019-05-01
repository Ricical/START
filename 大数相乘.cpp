/*117.大数相乘 (20分) 
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
一个整型变量只能用来存贮较小的n!的值，当 n 较大时，可将阶乘值中的每一个数字
放在一个一维数组的一个元素中。使用这方法，打印n!的值；
输入描述
整数n
输出描述
n!的值
输入样例
18
输出样例
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
   		c[i+1] = sum %10 + '0'; /*算出保留的数字*/
   		carry = sum/10;//进位 
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
