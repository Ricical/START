/*82.导弹拦截 (15分) 
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
某国为了防御敌国的导弹袭击，研发出一套导弹拦截系统。但是这种导弹拦截系统有一个缺陷：
虽然它的第一发拦截炮弹能够到达任意的高度，但是以后每一发拦截炮弹都不能高于前一发的高度。
某天，雷达捕捉到敌国的多枚导弹来袭。
输入描述
输入的第一行为导弹的个数n (0<n<10000),接下来的一行为导弹依次飞来的高度h（不大于
30000 的正整数）
输出描述
输出最多拦截的导弹个数。
输入样例
6
5 3 2 4 1 3

输出样例
4*/

#include <iostream>
#include <cstring>
using namespace std;

const int inf=1e9+9;
int n,a[30009][2];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][0];
	}
	for(int i=1;i<=n;i++){
		int ans=1,b[30009];
		memset(b,0,sizeof(b));
		b[0]=inf;
		for(int j=i+1;j<=n;j++){
			if(a[j][0]<a[i][0] && a[j][0]<b[ans-1]){
				b[ans]=a[j][0];
				++a[i][1];
				++ans;
			} 
		}
	}
	int max=0;
	for(int i=1;i<=n;i++){
		if(max<a[i][1]) max=a[i][1];
	}
	++max;
	cout<<max<<endl; 
	return 0;
}
