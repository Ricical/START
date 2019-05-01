/*问题：在线性时间内，求一组数中的第k大的数字；
输入：第一行为数字n
第二行输入n个数字
第三行输入k
7 3
1 4 3 9 8 7 2
5
10 4
11 7 6 5 8 9 13 2 18 12
0*/
#include<iostream>
#include<cstdio>
#include <vector>

using namespace std;
vector<int> a,b;
int k,n;

int find(int x){
	for(int i=0;i<n;i++){
		if(b[i]==x) return i; 
	}
	return -1;
}

int Partition (int low,int high){
	int temp = a[low];
	int pt   = a[low];
	while (low != high){
		while (low < high && a[high] >= pt)
			high--;
		a[low] = a[high];		
		while (low < high && a[low] <= pt)
			low++;
		a[high] = a[low];
	}	
	a[low] = temp;
	return low;
}
 
void QSort (int low, int high){
	int pl;
	if (low < high){
		pl = Partition (low,high);
		QSort (low,  pl-1);
		QSort (pl+1, high);
	}
}

void findk(int low,int high){
	int temp;
	temp=Partition(low,high);
	if(temp==n-k){
		cout<<find(a[temp])<<endl;
//		cout<<a[temp]<<endl;
	}
	else if(temp<n-k)
		findk(temp+1,high);
	else
		findk(low,temp-1);
}

int main(){
	int x;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x; 
		a.push_back(x);
		b.push_back(x);
	}
	findk(0,n-1); 
	QSort(0,n-1);	
	return 0;
}

