#include<cstdio>
#include<map>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int n;
int main(){
#ifdef XS
	freopen("hdu6161.in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
char s[10];
map<int ,ll> down,val;
#define ls(z) ((z)<<1)
#define rs(z) ((z)>>1)
#define lc(z) ls(z)
#define rc(z) (ls(z)|1)
#define fa(z) rs(z)
#define getv(z) (val.count(z)?val[z]:z)
ll cal(int x){
	if(x>n)return 0;
	if(down.count(x))return down[x];
	int ori=x;
  ll res=0;
	int ll = 0,rl=0;
	while(lc(x)<=n){
		ll++;x=lc(x);
	}
	x=ori;
	while(rc(x)<=n){
		rl++;x=rc(x);
	}
	if(ll!=rl)x=n;
	while(x>=ori){
		res+=x;x=fa(x);
	}
	return res;
}
ll que(int x){
	ll res=cal(lc(x))+cal(rc(x))+getv(x);
	ll sti=0;
	int ori=x;
	while(fa(x)){
		sti+=getv(fa(x));
		if(x&1){//rc
			x=fa(x);
			res=max(res,sti+cal(ori)+cal(lc(x)));
		}
		else {//x from lc
			x=fa(x);
			res=max(res,sti+cal(ori)+cal(rc(x)));
		}
	}
	return res;
}
void modi(int u,ll x){
	val[u]=x;
	while(u){
		down[u]=max(cal(lc(u)),cal(rc(u)))+getv(u);
		u=fa(u);
	}
}
void inp(){
	int m; if(scanf("%d%d",&n,&m)==EOF)exit(0);
	if(!n&&!m)exit(0);
	ll u,x;
	down.clear(),val.clear();
	for(int i=1;i<=m;i++){
		scanf("%s",s);
		if(s[0]=='q'){
			scanf("%lld",&u);
			printf("%lld\n",que(u));
		}
		else {
			scanf("%lld%lld",&u,&x);
			modi(u,x);
		}
	}
}
//hdu6161.cc by xsthunder at Thu Aug 24 08:52:23 2017

//AC at Thu Aug 24 10:05:09 2017
 
