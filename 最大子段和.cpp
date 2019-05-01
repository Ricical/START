/*120.最大子段和 (20分) 
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
实数序列a[1],a[2],...a[n], 一个子段指一段连续的子序列a[i],a[i+1],...a[j], 其中1<=i<=j<=n. 要求给出具有最
大和的子段。要求算法时间复杂性为o(n)。
输入描述
第一行输入一个整数n,表示原序列共有n个数据；
第二行输入n个实数，用空格隔开。
输出描述
最大和的子段，每个数据也用空格隔开。
（本题的测试数据能保证最大和的那一个子段是唯一的）
输入样例
7
-1 3 -2 4 -1 6 -5
输出样例
3 -2 4 -1 6*/
#include <iostream>
#include <vector>
using namespace std;

const int maxn=1e6+9;
int n;
double d[maxn],a[maxn];

void FillD(){
	d[0]=0;
	int str=0,end=1;
	double max=0,min=10000000;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
		if(max<d[i]){
			max=d[i];
			end=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(min>d[i] && str<end){
			min=d[i];
			str=i;
		}
	}
	for(int i=str+1;i<=end;i++){
		cout<<a[i]<<' ';
	}
}


int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	FillD();
	return 0;
} 
