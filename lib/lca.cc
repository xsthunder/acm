#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("lca.in","r",stdin);
#endif
	int n;scanf("%d",&n);for(int i=1;i<=n;i++) inp();
	return 0;
}
namespace Tree{
	static const int N = 40000+100;
	static const int NE=2*N;
	int n;
	int ecnt=0,head[N];
	struct E{ int f,t,w,n;void set(int f,int t,int w,int n){this->f=f,this->t=t,this->w=w,this->n=n;}
	}es[NE];
	void initTree(){ ecnt=0; MS(head,-1),MS(es,0); }
	void ae(int f,int t,int w){ es[ecnt].set(f,t,w,head[f]),head[f]=ecnt,ecnt++; }
};
namespace Lca{
	//depend Tree cmath/log2 std::swap
	using namespace Tree;
	static const int DEP=16;//log2(n)
	int p[N][DEP];//N*DEP
	int dep[N];
	int dist[N];
	int lca(int a,int b){
		if(dep[a]>dep[b])swap(a,b);
		int f=dep[b]-dep[a];
		for(int i = 0;(1<<i)<=f;i++){
			if((1<<i)&f)b=p[b][i];
		}
		if(a!=b){
			for(int i=(int)log2(N);i>=0;i--){
				if(p[a][i]!=p[b][i]){
					a=p[a][i],b=p[b][i];
				}
			}
			a=p[a][0];
		}
		return a;
	}
	void dfs(int rt,int fa){
		E e;
		for(int i =head[rt];i!=-1;i=e.n){
			e=es[i];
			if(e.t==fa)continue;
			dep[e.t]=dep[e.f]+1;
			dist[e.t]=dist[e.f]+e.w;
			p[e.t][0]=e.f;
			dfs(e.t,e.f);
		}
	}
	void initLca(int rt){
		MS(p,0);MS(dep,0);MS(dist,0);
		dfs(rt,-1);
		for(int i =1;(1<<i)<=n;i++){
			for(int j=1;j<=n;j++){
				p[j][i]=p[p[j][i-1]][i-1];
			}
		}
	}
};
void inp(){
	using namespace Lca;
	int m; scanf("%d%d",&n,&m);
	int f,t,w;
	initTree();
	for(int i=0;i<n-1;i++){
		scanf("%d%d%d",&f,&t,&w);
		ae(f,t,w),ae(t,f,w);
	}
	initLca(1);
	int a,b,ans;
	for(int i =0;i<m;i++){
		scanf("%d%d",&a,&b);
		f = lca(a,b);
		ans=dist[a]+dist[b]-dist[f]-dist[f];
		printf("%d\n",ans);
	}
}
//lca.cc by xsthunder at Wed Aug 23 09:44:59 2017

