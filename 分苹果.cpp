#include <iostream>
#include <cstring>
using namespace std;

const int maxn=109;
int a[maxn][maxn];
int solve(int m,int n){
	if(m<0) return 0;
	else if(n==1||m==0) return 1;
	else{
		if(a[m][n]==-1) a[m][n]=solve(m-n,n)+solve(m,n-1);
		return a[m][n];
	}	
}
int main(){
	int m,n,t;
	cin>>t;
	while(t--){
		int x;
		cin>>m;
		cin>>n;	
		memset(a,-1,sizeof(a));	
		x=solve(m,n);
		cout<<x<<endl;
	}
	return 0;
} 
