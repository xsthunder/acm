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
const ll mod= 1000000007;

ll qp(ll x,ll p){
	ll b = 1;
	while(p){
		if(p&1){ b*=x; b%=mod; }
		p>>=1;
		x*=x;
		x%=mod;
	}
	return b;
}
ll n,m;
void inp(){
	scanf("%lld%lld",&m,&n);
	if(m==1)printf("%lld",n);
	else printf("%lld",(qp(m,n)-1)*qp(m-1,mod-2)%mod);
	putchar('\n');
}
//hit3152b.cc by xsthunder at Tue Aug 29 21:37:03 2017

//AC at Tue Aug 29 21:50:09 2017
 
