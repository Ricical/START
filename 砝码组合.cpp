/*66.砝码组合 (15分) 
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
用天平称重时，我们希望用尽可能少的砝码组合称出尽可能多的重量。
如果只有5个砝码，重量分别是1，3，9，27，81。
则它们可以组合称出1到121之间任意整数重量（砝码允许放在左右两个盘中）。
本题目要求编程实现：对用户输入的重量(1~121)，
给出砝码组合方案（用加减式表示，减代表砝码放在物品盘）。
例如：
输入：
5
输出：
9-3-1
输入：
19
输出：
27-9+1
要求程序输出的组合总是大数在前小数在后。
输入描述
用户输入的重量(1~121)，
输出描述
给出砝码组合方案（用加减式表示，减代表砝码放在物品盘）。
输入样例
19
输出样例
27-9+1*/

#include <iostream>
using namespace std;

int n;
int cnt[5];
int a1[3]={-1,0,1},a3[3]={-3,0,3},a9[3]={-9,0,9},a27[3]={-27,0,27},a81[3]={-81,0,81};

void solve(){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					for(int m=0;m<3;m++){
						if(a1[m]+a3[l]+a9[k]+a27[j]+a81[i] == n){
							cnt[0]=a81[i];
							cnt[1]=a27[j];
							cnt[2]=a9[k];
							cnt[3]=a3[l];
							cnt[4]=a1[m];
							return;
						}
					}
				}
			}
		}
	}
}

int main(){
	cin>>n;
	
	solve(); 
	int start=0;
	for(int i=0;i<5;i++){
		if(cnt[i]>0){
			start=i;
			break;
		}
	}
	cout<<cnt[start];
	for(int i=start+1;i<5;i++){
		if(cnt[i]>0){
			cout<<"+"<<cnt[i];
		}
		if(cnt[i]<0) cout<<cnt[i];
	}
	return 0;
} 
