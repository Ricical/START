/*Id:[61]         快乐 (5分)
(C时间限制：3?毫秒?|?
                        C内存限制：1000?Kb)
题目内容:
没有买到奥运会的门票让YF伤心不已，为了使自己开心起来，他去找周围的人聊天，每找一个人聊天，他就会耗费一定的体力，但
他会得到一定量的快乐。YF试图使自己尽可能的高兴，但一旦体力耗尽了(为零或为负)，他也就挂了，就一点快乐都没有了。现
在Yk初始有100点体力，他最多可以获得多少快乐？

输入描述:
数据分多组，对于每组数据：第一行为n，表示有YK的n(0<n<21)个朋友。第二行表示和每个人聊天耗费的体力，第三行表示每个
人所能提供的快乐值。输入以一个0结束。
输出描述:
对于每组输出，输出一个值，YK可以获得的最大的快乐值。
输入样例:
3
1 21 79
20 30 25
4
100 100 100 100
1 2 3 4
0

输出样例:
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
