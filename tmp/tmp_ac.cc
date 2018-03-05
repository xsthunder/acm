#include<cstdio>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 1e5+1000;
int ecnt,head[N];
int w[N],pc[N],pw[N];
struct E{
	int f,t,w,n;
	void set(int f,int t,int w,int n){this->f=f,this->t=t,this->w=w,this->n=n;}
}es[N*2];
void ae(int f,int t,int w){ es[ecnt].set(f,t,w,head[f]);head[f]=ecnt;ecnt++; }
int dfs(int rt,int fa){
	E e;int i;int cnt=0;
	for(i =head[rt];i!=-1;i=e.n){
		e=es[i];
		if(e.t==fa)continue;
		cnt+=pc[e.t]=dfs(e.t,rt);
	}
	cnt++;
	return cnt;
}
void inp(){
	MS(head,-1);ecnt=0;
	int n,i,f,t,w; scanf("%d",&n);
	for(i=2;i<=n;i++){ t=i,scanf("%d%d",&f,&w);ae(f,t,w),ae(t,f,w);pw[i]=w; }
	assert(dfs(1,-1)==n);
	ll ans=0;
#define calw(z) (ll(pw[z])*(ll(n-pc[z]))*(ll(pc[z])))
	for(i=2;i<=n;i++){ ans+=calw(i); }
	printf("%lld\n",ans);
	int m;scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&t,&w);
		ans-=calw(t);
		pw[t]=w;
		ans+=calw(t);
		printf("%lld\n",ans);
	}
}
//tmp.cc by xsthunder at Sat Sep  9 10:20:04 2017

//AC at Sat Sep  9 18:49:28 2017
 
