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
ll exgcd(ll a,ll b,ll &x, ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a%b, x,y);
	ll tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return gcd;
}
void inp(){
	ll a,b,x,y,c = 1;
	if(scanf("%lld%lld",&a,&b)==EOF)exit(0);
	ll gcd = exgcd(a,b,x,y);
	if(c % gcd != 0){ puts("sorry");return; }
	x *= c/gcd;
	y *= c/gcd;
	a /=gcd;
	b /=gcd;
	swap(a,b);
	if(x < 0){
		ll t = (-x+a-1)/a;
		x = x + a*t;
		y = y - b*t;
	}
	else {
		ll t = (x)/a;
		x = x - a*t;
		y = y + b*t;
	}
	printf("%lld %lld\n", x,y);
}
//hdu2669.cc by xsthunder at Thu Nov  9 14:11:11 2017

//AC at Thu Nov  9 14:19:56 2017
 
