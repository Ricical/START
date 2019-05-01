/*120.����Ӷκ� (20��) 
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
ʵ������a[1],a[2],...a[n], һ���Ӷ�ָһ��������������a[i],a[i+1],...a[j], ����1<=i<=j<=n. Ҫ�����������
��͵��ӶΡ�Ҫ���㷨ʱ�临����Ϊo(n)��
��������
��һ������һ������n,��ʾԭ���й���n�����ݣ�
�ڶ�������n��ʵ�����ÿո������
�������
���͵��ӶΣ�ÿ������Ҳ�ÿո������
������Ĳ��������ܱ�֤���͵���һ���Ӷ���Ψһ�ģ�
��������
7
-1 3 -2 4 -1 6 -5
�������
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
