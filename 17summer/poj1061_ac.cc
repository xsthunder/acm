#include<cstdio>
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
	while(1)inp();
	return 0;
}
ll exgcd (ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a%b, x ,y);
	ll tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return gcd;
}
ll mabs(ll z){
	if(z<0)z = -z;
	return z;
}
void inp(){
	ll x,y,m,n,L;
	if(scanf("%lld%lld%lld%lld%lld", &x,&y,&m,&n,&L)==EOF)exit(0);
	ll a = (m-n), b = L, c = y-x;
	ll gcd = exgcd(a,b,x,y);
	if(c % gcd != 0){
		puts("Impossible");return;
	}
	if( a == 0){
		if( x%m == y%m)puts("0");
		else puts("Impossible");
		return;
	}
	x *= c/gcd;
	y *= c/gcd;
	a /= gcd;
	b /= gcd;
	swap(a,b);
//	printf("%lld %lld %lld %lld \n",x,a,y,b);
	a = mabs(a);
	if( x < 0){
		x += mabs(a*((-x+a-1)/a));
	}
	else {
		x -= x/a*a;
	}
	printf("%lld\n", x);
}
//poj1061.cc by xsthunder at Thu Nov  9 12:27:24 2017

//AC at Thu Nov  9 13:33:40 2017
 
