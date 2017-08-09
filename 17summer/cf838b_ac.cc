#include<cstdio>
#include<stack>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("cf838b.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int N = 2e5+10;
ll dis[N], exp[N], id[N], en[N],head[N];
int ecnt1=1,ecnt2=1;
struct E{
	int f,t,c,n;
	void set(int f,int t,int c,int n){this->f=f,this->t=t,this->c=c,this->n=n;}
}es1[N],es2[N];
void ae1(int f,int t,int c){
	es1[ecnt1].set(f,t,c,head[f]);
	head[f]=ecnt1++;
}
void ae2(int f,int t,int c){
	es2[ecnt2++].set(f,t,c,-2);
}
struct S{
	int v,n;
	S(int v,int n){this->v=v,this->n=n;}
};
int tim=0;
void dfs(){
	stack<S> sk;
	id[1]=++tim;
	dis[1]=0;
	sk.push(S(1,head[1]));
	E e;
	while(!sk.empty()){
		S s = sk.top();sk.pop();
		if(s.n!=-1){
			e=es1[s.n];
			id[e.t]=++tim;
			dis[e.t]=dis[e.f]+e.c;
			sk.push(S(e.f,e.n));
			sk.push(S(e.t,head[e.t]));
		}
		else en[s.v]=tim;
	}
}
#define mid int m=(L+R)>>1
#define lson(z) (rt<<1)
#define rson(z) ((rt<<1)+1)
#define pl L, m
#define pr m+1,R
struct W{ll id,v;};
bool operator < (W a,W b){return a.v==b.v?(a.id<b.id):(a.v<b.v);};
struct T{ ll v,laz;W mi; };
T T1[3*N];
T T2[3*N];
int rid[N];
void bui(int rt,int L,int R){
	if(L==R){ 
		T1[rt].mi.v=T1[rt].v=dis[rid[L]],T2[rt].mi.v=T2[rt].v=dis[rid[L]]+exp[rid[L]]; 
		T1[rt].mi.id=T2[rt].mi.id=rid[L];
		return;
	}
	mid;
	bui(lson(rt),pl);
	bui(rson(rt),pr);
	T1[rt].mi=min(T1[lson(rt)].mi,T1[rson(rt)].mi);
	T2[rt].mi=min(T2[lson(rt)].mi,T2[rson(rt)].mi);
}
void upd(T TT[],int l,int r,ll c,int rt,int L,int R){
	if(r<L||R<l)return;
	if(l<=L&&R<=r){
		if(L==R){
			TT[rt].mi.v+=c;
			return ;
		}
		TT[rt].laz+=c;
		TT[rt].mi.v+=c;
		return;
	}
	mid;
	if(TT[rt].laz){
		upd(TT,pl,TT[rt].laz,lson(rt),pl);
		upd(TT,pr,TT[rt].laz,rson(rt),pr);
		TT[rt].laz=0;
	}
	upd(TT,l,r,c,lson(rt),pl);
	upd(TT,l,r,c,rson(rt),pr);
	TT[rt].mi=min(TT[lson(rt)].mi,TT[rson(rt)].mi);
}
int inf=0x7fffffff;
W que(T TT[],int l,int r,int rt,int L,int R){
	if(l<=L&&R<=r){
		return TT[rt].mi;
	}
	if(r<L||R<l){
		W w;w.id=-3;w.v=inf;
		return w;
	}
	mid;
	if(TT[rt].laz){
		ll c=TT[rt].laz;
		upd(TT,pl,c,lson(rt),pl);
		upd(TT,pr,c,rson(rt),pr);
		TT[rt].laz=0;
	}
	return min(
			que(TT,l,r,lson(rt),pl)
			,que(TT,l,r,rson(rt),pr));
}
void inp(){
	int n,q;scanf("%d%d",&n,&q);
	MS(head,-1);
	int i; int a,b,c;
	for(i=0;i<n-1;i++){ scanf("%d%d%d",&a,&b,&c); ae1(a,b,c);}
	for(i=0;i<n-1;i++){	scanf("%d%d%d",&a,&b,&c); exp[a]=c;ae2(a,b,c); }
	dfs();
	for(i=1;i<=n;i++){rid[id[i]]=i;};
	bui(1,1,n);
	int v;
	ll ans;
	for(i=0;i<q;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a==1){//change
			if(b<=n-1){
				int d=c-es1[b].c;
				v = es1[b].t;
				upd(T1,id[v],en[v],d,1,1,n);
				upd(T2,id[v],en[v],d,1,1,n);
				es1[b].c=c;
			}
			else {
				b-=n-1;
				v=es2[b].f;
				upd(T2,id[v],id[v],c-exp[v],1,1,n);
				exp[v]=c;
			}
		}
		else {
			ans = inf;
			if(b==c){puts("0");continue;};
			if(id[b]<=id[c]&&id[c]<=en[b]){
				ans=min(ans,que(T1,id[c],id[c],1,1,n).v-
						que(T1,id[b],id[b],1,1,n).v);
			}
			W x = que(T2,id[b],en[b],1,1,n);
			x.v-=que(T1,id[b],id[b],1,1,n).v;
			x.v+=que(T1,id[c],id[c],1,1,n).v;
			ans = min(ans,x.v);
			printf("%lld\n",ans);
		}
	}
}
//cf838b.cc by xsthunder at Mon Aug  7 19:10:22 2017

//AC at Tue Aug  8 19:56:39 2017
 
