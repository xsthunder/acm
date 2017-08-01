#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("spoj375.in","r",stdin);
#endif
	int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int N = 10000 + 1000;
struct Ed{
	int f,t,w,n;
}E[N*2];
int head[N];
int n,Ecnt;
inline void ae(int f,int t,int w){
	E[Ecnt].f = f;
	E[Ecnt].t = t;
	E[Ecnt].n = head[f];
	E[Ecnt].w = w;
	head[f] = Ecnt;
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
int st[N*4], ma[N*4];// no need of st
int que(const int l,const int r,const int rt, const int L,const int R){
	if(l<= L && R <= r)return ma[rt];
	if(r < L || R < l)return -1e9;
	mid;
	return max(que(l,r,lson(rt),pl),
			que(l,r,rson(rt), pr));
}
int Q(int u,int v){
	int rt = 1;
	int ans = 0;
	while(top[u] !=  top[v]){
		if(dep[top[u]] < dep[top[v]])swap(u,v);
		ans = max(ans ,que(id[top[u]] ,id[u], rt, 1,idcnt));
		u = fa[top[u]];
	}
	if(dep[u] < dep[v])swap(u,v);
	ans = max(ans ,que(id[son[v]] ,id[u], rt, 1,idcnt));
	return ans;
}
void upd(const int u,const int w,const int rt,const int L,const int R){
	mid;
	if(L == R){ ma[rt] = st[rt] = w; return; }
	if(u<=m)upd(u,w,lson(rt),pl);
	else upd(u,w,rson(rt),pr);
	pushup(rt);
}
void sol(){
	char s[20];
	int rt = 1;
	int u,v,w;
	while(scanf("%s",s)!=EOF){
		if(s[0] == 'Q'){
			scanf("%d%d", &u,&v);
			int ans = Q(u, v);
			printf("%d\n",ans);
		}
		else if(s[0] == 'C'){
			scanf("%d%d", &u, &w);
			E[u].w = w;
			upd(id[E[(u-1)*2].t],w,rt,1,idcnt);
		}
		else if(s[0] == 'D')return;
	}
}
void bui(const int rt ,const int L,const int R){
	if(L == R){
		ma[rt] = st[rt] = val[L];
		return;
	}
	mid;
	bui(lson(rt), pl);
	bui(rson(rt), pr);
	pushup(rt);
}
void inp(){
	memset(head,-1,sizeof(head));Ecnt = 0;idcnt = 0;
	MS(top),MS(dep),MS(E),MS(son),MS(val),MS(fa),MS(ma),MS(st),MS(id),MS(siz);
	scanf("%d",&n);
	int u,v,w,i;
	for(int i =1;i<=n-1;i++){
		scanf("%d%d%d",&u,&v,&w);
		ae(u,v,w);
		ae(v,u,w);
	}
	int rt = 1,de = 1;
	dfs1(rt, 0, de);
	dfs2(rt, rt);
	val[rt] = -1e9;
	for(i = 0;i<Ecnt;i++){
		Ed &e = E[i];
		if(dep[e.f] > dep[e.t])swap(e.f,e.t);
		val[id[e.t]] = e.w;
	}
	bui(rt, 1, idcnt);
	sol();
}
//spoj375.cc by xsthunder at Mon Jul 31 14:13:44 2017

//AC at Mon Jul 31 21:50:01 2017
 
