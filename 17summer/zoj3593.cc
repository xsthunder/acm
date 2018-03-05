#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	freopen("zoj3593.in","r",stdin);
#endif
	int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){ x = 1; y = 0; return a; }
	ll gcd = exgcd(b,a%b,x,y);
	ll tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return gcd;
}
const ll inf = 0x3fffffffffffffffLL;
ll cal(ll,ll,ll);
void inp(){
	ll a,b,c,A,B;
	scanf("%lld%lld%lld%lld",&A,&B,&a,&b);
	c = B - A;c = abs(c);
	if(!a || !b || (a==b)){
		if(a>b)swap(a,b);
//		cout<<"hello"<<endl;
		if(c % b == 0)printf("%lld\n", (c+b)/(2*b) );
		else puts("-1");
		return;
	}
	ll ans;
	ans = cal(a,b,c);
	ans = min(ans, cal(a+b,b,c));
	ans = min(ans, cal(a+b,a,c));
	printf("%lld\n",ans==inf?-1LL:ans);
}
ll cal(ll a,ll b, ll c){
	ll x,y;
	ll gcd = exgcd(a,b,x,y);
	if(c % gcd != 0){
		return inf;
	}
	x *= (c/gcd);
	y *= (c/gcd);
	a/=gcd;
	b/=gcd;
	swap(a,b);
	ll ans = abs(x) + abs(y);
	ll L = -x/a;
	ll R = y/b;
	ll mid = -(x+y)/(a-b);//check a == b 
	ll tmp,tmpx,tmpy;
	for(ll t = L-1;t<=L+1;t++){
		tmpx = x+a*t;
		tmpy = y-b*t;
		tmp = abs(tmpx)+abs(tmpy);
		ans = min(ans, tmp);
	}
	for(ll t = R-1;t<=R+1;t++){
		tmpx = x+a*t;
		tmpy = y-b*t;
		tmp = abs(tmpx)+abs(tmpy);
		ans = min(ans, tmp);
	}
	for(ll t = mid-1;t<=mid+1;t++){
		tmpx = x+a*t;
		tmpy = y-b*t;
		tmp = abs(tmpx)+abs(tmpy);
		ans = min(ans, tmp);
	}
	return ans;
}
//zoj3593.cc by xsthunder at Mon Nov  6 23:50:45 2017

