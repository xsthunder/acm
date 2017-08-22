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
#ifdef XS
    freopen("sam.in","r",stdin);
#endif
		while(1) inp();
    return 0;
}
const int N = 100000 + 1000;
struct Ed{ int f,t,n; }E[N*2]; int head[N]; int n,Ecnt;
inline void ae(int f,int t){
    E[Ecnt].f = f; E[Ecnt].t = t; E[Ecnt].n = head[f]; head[f] = Ecnt;
    Ecnt++;
}
int fa[N],de[N];
void dfs(int rt,int f,int d){
	de[rt]=d;
	fa[rt]=f;
	Ed e;
	for(int i=head[rt];i!=-1;i=e.n){
		e=E[i];
		if(e.t==f)continue;
		dfs(e.t,rt,d+1);
	}
}
int val[N];
void inp(){
	memset(head,-1,sizeof(head));Ecnt = 0;
	int m;if(scanf("%d%d",&n,&m)==EOF)exit(0);
	if(!n&&!m)exit(0);
	for(int i =1;i<=n;i++)scanf("%d",&val[i]);
	int u,v;
	for(int i =1;i<=n-1;i++){ scanf("%d%d",&u,&v);
		ae(u,v); ae(v,u); }
	dfs(1,-1,0);
	int x,y,a,b;
	for(int i=1;i<=m;i++){
		ll ans=0;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		while(x!=y){
			if(de[x]<de[y])swap(x,y);
			int v=val[x];
			if(a<=v&&v<=b)ans+=v;
			x=fa[x];
		}
		int v=val[x];
		if(a<=v&&v<=b)ans+=v;
		if(i!=1)putchar(' ');
		printf("%lld",ans);
	}
	putchar('\n');
}

