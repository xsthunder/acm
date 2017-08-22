#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
	freopen("input","r",stdin);
	freopen("output.my","w",stdout);
#ifdef XS
    freopen("input","r",stdin);
#endif
		while(1) inp();
    return 0;
}
const int N = 100000 + 1000;
struct Ed{ int f,t,n; }E[N*2]; int head[N]; int n,Ecnt;
struct Nod{int l,r;ll s;}nod[30*N];int nodcnt; int root[N];
inline void ae(int f,int t){
    E[Ecnt].f = f; E[Ecnt].t = t; E[Ecnt].n = head[f]; head[f] = Ecnt;
    Ecnt++;
}
int siz[N],dep[N],son[N],fa[N];
void dfs1(int rt,int ff, int d){
    int w = 0,i,u; siz[rt] = 1; fa[rt] = ff; dep[rt] = d; son[rt] = 0;
    for(i = head[rt]; i!= -1; i = E[i].n){
        u = E[i].t;
        if(u == fa[rt])continue;
        dfs1(u ,rt, d +1 );
        siz[rt] += siz[u];
        if(siz[u] > w){
            son[rt] = u; w = siz[u];
        }
    }
}
int top[N],id[N],idcnt;
void dfs2(int rt ,int to){
    top[rt] = to; id[rt]=++idcnt ;
    int u,i;
    if(son[rt])dfs2(son[rt], to);
    for(i = head[rt]; i!= -1; i = E[i].n){
        u = E[i].t;
        if(u == fa[rt] || u == son[rt])continue;
        dfs2(u,u);
    }
}
#define lson(z) z<<1
#define rson(z) (z<<1)+1
#define mid int m = (L+R)>>1;
#define pl L, m
#define pr m+1, R
#define pushup(z) ma[z] = max(ma[lson(z)], ma[rson(z)])
int val[N];
ll que(int rt,int l,int r,int L,int R){
	if(l<=L&&R<=r)return nod[rt].s;
	if(r<L||R<l)return 0;
	mid;
	return que(nod[rt].l,l,r,pl)
		+que(nod[rt].r,l,r,pr);
}
int unq[N*2];
int rid[N],unqsize;
int getvalid(int x){
	return lower_bound(unq+1,unq+1+unqsize,x)-unq;
}
ll Q(int u,int v,int a,int b){
	if(dep[v]+dep[u]<300){
		ll ans=0;
		int x=u,y=v;
		while(x!=y){
			if(dep[x]<dep[y])swap(x,y);
			int v=val[x];
			if(a<=v&&v<=b)ans+=v;
			x=fa[x];
		}
		int v=val[x];
		if(a<=v&&v<=b)ans+=v;
		return ans;
	}
	ll ans = 0;
	a=getvalid(a),b=getvalid(b);
	while(top[u] !=  top[v]){
		if(dep[top[u]] < dep[top[v]])swap(u,v);
		ans += que(root[id[u]],a,b,1,unqsize);
		u = fa[top[u]];
	}
	if(dep[u] < dep[v])swap(u,v);
	ans += que(root[id[u]],a,b,1,unqsize);
	if(top[v]!=v&&top[fa[v]]==top[v])ans-=que(root[id[fa[v]]],a,b,1,unqsize);
	return ans;
}
struct Query{
	int x,y,a,b;
	void set(int x,int y,int a,int b){this->x=x,this->y=y,this->a=a,this->b=b;}
}queries[N];
void sol(int m){
	int u,v,a,b;
	for(int i =1;i<=m;i++){
		u=queries[i].x,v=queries[i].y,a=queries[i].a,b=queries[i].b;
		ll ans = Q(u, v,a,b);
		if(i!=1)putchar(' ');
		printf("%lld",ans);
	}
	putchar('\n');
}
void bui(int &rt,int val,int id,int L,int R){
	nod[nodcnt]=nod[rt];
	rt=nodcnt;nodcnt++;
	nod[rt].s+=val;
	if(L==R)return ;
	mid;
	if(id<=m){
		bui(nod[rt].l,val,id,pl);
	}
	else bui(nod[rt].r,val,id,pr);
}

void pcmt(int rt,int w = 0){
#define get(z) nod[z]
	if(get(rt).r!=0)pcmt(get(rt).r, w+10);
	printf("%*sn[%d]l:%dr:%ds:%lld\n", w,"", rt,get(rt).l,get(rt).r,get(rt).s);
	if(get(rt).l!=0)pcmt(get(rt).l, w+10);
}
void initroot(){
	top[0]=0;rid[0]=0;
	int v=0,vid;
	for(int i =1;i<=n;i++)rid[id[i]]=i;
	for(int i =1;i<=n;i++){
		if(top[rid[i-1]]==top[rid[i]]){ root[i]=root[i-1]; }
		else root[i]=0;
		v = val[rid[i]]; vid=getvalid(v);
		bui(root[i],v,vid,1,unqsize);
	}
#ifdef XS
	for(int i=1;i<=n;i++){
		printf("----vvvvvvvvvvroot[%d]\n",i);
		pcmt(root[i]);
	}
#endif
}

void inp(){
	memset(head,-1,sizeof(head));Ecnt = 0;idcnt = 0;
	MS(top),MS(dep),MS(E),MS(son),MS(val),MS(fa),MS(id),MS(siz);
	MS(nod),nodcnt=1,MS(root);
	int m;if(scanf("%d%d",&n,&m)==EOF)exit(0);
	if(!n&&!m)exit(0);
	for(int i =1;i<=n;i++)scanf("%d",&val[i]);
	int u,v;
	for(int i =1;i<=n-1;i++){ scanf("%d%d",&u,&v);
		ae(u,v); ae(v,u); }
	memcpy(unq,val,sizeof(val));
	int x,y,a,b;
	unqsize=n;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&x,&y,&a,&b);
		queries[i].set(x,y,a,b);
		unq[++unqsize]=a;
		unq[++unqsize]=b;
	}
	sort(unq+1,unq+1+unqsize);
	unqsize=unique(unq+1,unq+1+unqsize)-(unq+1);
	int rt = 1,de = 1;
	dfs1(rt, 0, de);
	dfs2(rt, rt);
	initroot();
	sol(m);
}

