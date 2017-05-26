#include<iostream>
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
typedef long long ll;
ll inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i =1;i<=t;i++){
		cout<<"Case #"<<i<<": "<<inp()<<endl;
	}
	return 0;
}
ll inp(){
	ll n;
	cin>>n;
	return (2+n)*(n-1)/2;
}
//A.cc by xsthunder at Tue May 16 18:04:26 2017

//AC at Tue May 16 18:29:38 2017
 
