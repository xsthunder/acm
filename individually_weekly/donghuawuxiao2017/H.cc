#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
int a[200];
void inp(){
	int n;
	if(!(cin>>n))exit(0);
	for(int i =0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++){
		a[i]=(a[i]+a[i-1])/2;
	}
	cout<<a[n-1]<<endl;
}
//H.cc by xsthunder at Fri May 26 19:07:17 2017

