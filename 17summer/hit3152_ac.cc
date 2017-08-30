#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
ll mod=1000000007;
ll qp(ll x,ll p){
	ll b=1;
	while(p){
		if(p&1){
			b*=x;
			b%=mod;
		}
		x*=x;
		x%=mod;
		p>>=1;
	}
	return b;
}
ll m;
ll rec(int n){
	if(n==1)return 1;
	ll ans=0;
	if(n&1){
		ans=qp(m,n-1);n--;
	}
	ans+=rec(n/2)*(1+qp(m,n/2));
	return ans%mod;
}
void inp(){
	ll n;scanf("%lld%lld",&m,&n);
	ll ans=rec(n);
	printf("%lld\n",ans);
}
//hit3152.cc by xsthunder at Tue Aug 29 21:28:04 2017

//AC at Tue Aug 29 21:35:34 2017
 
