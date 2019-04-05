#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	try{
		//while(1)
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 2e5+100;
ll sum[N];
void inp(){
	int n;
	scanf("%d",&n);
	MS(sum);
	for(int i =1;i<=n;i++){
		scanf("%lld",&sum[i]);
		sum[i]+=sum[i-1];
	}
	ll ans = abs(sum[n]-sum[n-1] - sum[n-1]);
	for(int i =1;i<n;i++){
		ll a = sum[i];
		ll b = sum[n]-sum[i];
		ans  = min(ans, abs(b-a));
	}
	printf("%lld\n", ans);
}
//C.cc by xsthunder at Sat Jul 15 20:02:11 2017

//AC at Sat Jul 15 20:40:00 2017
 
