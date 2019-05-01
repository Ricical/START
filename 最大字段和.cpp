#include <iostream>
#include <vector>
using namespace std;

const int maxn=1e6+9;
int n;
int d[maxn],a[maxn];

void FillD(){
	d[0]=a[0];
	for(int i=1;i<n;i++){
		d[i]=d[i-1]>0?d[i-1]+a[i]:a[i];
	}
}

int main(){
	cin>>n;
	int max=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	FillD();
	for(int i=0;i<n;i++){
		if(d[i]>max) max=d[i];
	}
	cout<<max<<endl;
	return 0;
} 
