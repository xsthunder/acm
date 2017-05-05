#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
#define iF if(Te)
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
const int N = 200;
int A[N];
int S [N];
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
void inp(){
	int x,n;
	cin>>n;
	A[0]=0;
	for(int i=0;i<n;i++){
		cin>>x;
		A[i]=x;
	}
	sort(A,A+n);
	S[0]=0;
	for(int i =1;i<=n;i++){
		S[i]+=S[i-1]+A[i-1];
	}
	for(int i=n-1;i>=0;i--){
//		cout<<A[n];
		if(S[n]-S[i]>S[i]){
			cout<<n-i<<endl;;
			return ;
		}
	}
}
//A.cc
//generated automatically at Sun Apr 30 19:11:18 2017
//by xsthunder

