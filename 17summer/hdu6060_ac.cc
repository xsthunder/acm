#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	//#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("hdu6060.in","r",stdin);
#endif
	while(1)
	inp();
	return 0;
}
const int N = 1e6 + 100;
struct E{
	int f,t,w,n;
	void s(int f,int t ,int w,int n){this->f = f,this->t = t,this->w = w,this->n =n ;}
}E[N*3];
int n,k,Ecnt,head[N],siz[N];
void ae(int f,int t ,int w){
	E[Ecnt].s(f,t,w,head[f]);
	head[f] = Ecnt;
	Ecnt++;
}
ll ans;
void dfs(int v,int fa,int w){
	siz[v] = 1;
	int u;
	for(int i = head[v]; i != -1; i = E[i].n){
		u = E[i].t;
		if(u == fa)continue;
		dfs(u,v,E[i].w);
		siz[v] += siz[u];
	}
	ans += (ll)w*min(siz[v],k);
}
void inp(){
	MS(E),Ecnt = 0,memset(head,-1,sizeof(head)),ans = 0,MS(siz);
	if(scanf("%d%d",&n,&k) == EOF)exit(0);
	int f,t,w;
	for(int i = 1;i<=n-1;i++){
		scanf("%d%d%d",&f,&t,&w);
		ae(f,t,w);
		ae(t,f,w);
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
}
//hdu6060.cc by xsthunder at Tue Aug  1 19:21:52 2017

//AC at Tue Aug  1 20:47:45 2017
 
