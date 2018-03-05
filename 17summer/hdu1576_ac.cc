#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
ll exgcd(ll a,ll b, ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b,a%b,x,y);
	ll tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return gcd;
}
const ll mod = 9973LL;
void inp(){
	ll a,b,x,y;ll A,B,c = 1;
	scanf("%lld%lld",&A,&B);
	a = B,b = mod;
	ll gcd = exgcd(a,b,x,y);
	x *= c/gcd;
	y *= c/gcd;
	a /= gcd;
	b /= gcd;
	swap(a,b);
	x = (x % mod + mod)%mod;
	printf("%lld\n", x * A %mod);
}
//hdu1576.cc by xsthunder at Thu Nov  9 13:41:42 2017

//AC at Thu Nov  9 13:50:13 2017
 
