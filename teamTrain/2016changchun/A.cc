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
	int t;
	cin>>t;
	while(t--)inp();
	return 0;
}
void inp(){
	int a,b;
	cin>>a>>b;
	if(a>b)swap(a,b);
	cout<<a+b*2<<endl;;
}
//A.cc by xsthunder at Tue May  9 18:20:24 2017

