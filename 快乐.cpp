/*Id:[61]         ���� (5��)
(Cʱ�����ƣ�3?����?|?
                        C�ڴ����ƣ�1000?Kb)
��Ŀ����:
û���򵽰��˻����Ʊ��YF���Ĳ��ѣ�Ϊ��ʹ�Լ�������������ȥ����Χ�������죬ÿ��һ�������죬���ͻ�ķ�һ������������
����õ�һ�����Ŀ��֡�YF��ͼʹ�Լ������ܵĸ��ˣ���һ�������ľ���(Ϊ���Ϊ��)����Ҳ�͹��ˣ���һ����ֶ�û���ˡ���
��Yk��ʼ��100���������������Ի�ö��ٿ��֣�

��������:
���ݷֶ��飬����ÿ�����ݣ���һ��Ϊn����ʾ��YK��n(0<n<21)�����ѡ��ڶ��б�ʾ��ÿ��������ķѵ������������б�ʾÿ��
�������ṩ�Ŀ���ֵ��������һ��0������
�������:
����ÿ����������һ��ֵ��YK���Ի�õ����Ŀ���ֵ��
��������:
3
1 21 79
20 30 25
4
100 100 100 100
1 2 3 4
0

�������:
50
0
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
struct node{
	int w;
	int v;
	double bizhi;
}a[25];

bool cmp(node a, node b){
	return a.bizhi > b.bizhi;
}

int main(){
	int sum=0;
	while(cin>>n){
		if(n==0) break;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].w;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].v;
			a[i].bizhi=a[i].v*1.0/a[i].w;
		}
		sort(a+1,a+1+n,cmp);
		for(int i=1,j=100;j>0 && i<=n;i++){
			if(a[i].w>=j) continue;
			else{
				sum+=a[i].v;
				j-=a[i].w;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
