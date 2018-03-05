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
	freopen("C.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
ll exgcd( ll a,ll b ,ll &x, ll &y){
	if(!b){
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
bool has( ll a,ll b,ll &x,ll &y,ll gcd){
	a /= gcd;
	b /= gcd;
	int t = (y - x)/(a+b);
	for(int i = t - 1;i <= t+1;i++){
		if( x + b*i >= 0 && y - a * i >=0){
			x = x + b*i;
			y = y - a*i;
			return 1;
		}
	}
	return 0;
}
void inp(){
	ll c,a,b;
	scanf("%lld%lld%lld",&c,&a,&b);
	if(a > b)swap(a,b);
	ll x,y;
	ll gcd = exgcd(a,b,x,y);
	if( c % gcd ){ 
		puts("-1");
		return; 
	}
	x *= c/gcd;
	y *= c/gcd;
	if(!has(a,b,x,y,gcd)){
		puts("-1");
		return;
	}
	int now;
	for(int i = 0;i<x;i++){
		for(int j = 0;j<a;j++){
			now = i*a + (j + 1)%a + 1;
			printf("%d ", now);
		}
	}
	for(int i = 0; i<y;i++){
		for(int j = 0;j<b;j++){
			now = a * x + i * b + (j + 1)%b + 1;
			printf("%d ", now);
		}
	}
}
//C.cc by xsthunder at Fri Feb 16 00:17:45 2018

