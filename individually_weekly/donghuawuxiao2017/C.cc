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
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
typedef long long ll;
const ll N = 2e5;
const ll mod = 1e9+7;
ll a[N];
ll b[N];
void inp(){
	int n,l;
	if(!(cin>>n>>l))exit(0);
	MS(a);
	MS(b);
	for(int i=1;i<=l;i++){
		a[i]=b[i-1]+1;
		b[i]=b[i-1]+a[i];
		b[i]%=mod;
	}
	for(int i=l+1;i<=n;i++){
		a[i]=(b[i-1]-b[i-1-l]+mod)%mod;
		b[i]=b[i-1]+a[i];
		b[i]%=mod;
	}
//	pA(a,n+1,3);
//	pA(b,n+1,3);
	cout<<a[n]%mod<<endl;
}
//C.cc by xsthunder at Fri May 26 09:55:29 2017

