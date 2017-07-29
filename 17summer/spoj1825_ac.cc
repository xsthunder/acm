#include<cstdio>
#include<algorithm>
#include<vector>
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
	freopen("spoj1825.in","r",stdin);
#endif
	try{
		while(1)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
int k,n;
int inf = 0x7fffffff;
const int N = 2e5  +100;
int mark[N];
typedef vector<P > VI;
typedef vector<VI> VII;
VII vii(N);
int root,cntrt;
int done[N];
int cc[N];//count child 
void getrt(int v, int fa){
	cc[v] = 1;int f = -inf;
	for(auto x: vii[v]){
		int u = x.first;
		if(u == fa || done[u])continue;
		getrt(u,v);
		cc[v] += cc[u];
		if(cc[u] > f)
			f = cc[u];
	}
	if(n - cc[v] > f)
		f = n - cc[v];
	if( f < cntrt){
		root = v;
		cntrt = f;
	}
}
int F[N],G[N];
typedef pair<int,pair< int,int > >cmar;
vector<cmar> vc;
int getmar(int v,int fa){
	int c = 0;
	for(auto x:vii[v]){
		int u = x.first;
		if(done[v]||u== fa)continue;
		c  = max( getmar(u,v), c);
	}
	c += mark[v];
	return c;
}
void getG(int v,int fa,int l,int c){
	if(G[c] < l)
		G[c] =l;
	for(auto x: vii[v]){
		int u = x.first, ul = x.second;
		if(done[u] || u == fa)continue;
		getG(u, v,ul + l, c + mark[u]);
	}
}
int ans;
void work(int v){
	done[v] = 1;
	vc.clear();
#define mk(a,b) make_pair(a,b)
	for(auto x: vii[v]){
		int u = x.first, l = x.second;
		if(done[u])continue;
		int c = getmar(u,v);
		vc.push_back(mk(c,mk(u,l)));
	}
	sort(vc.begin(),vc.end());
	if(!vc.empty())for(int i = 0;i<=vc[vc.size()-1].first;i++){
		G[i] = F[i] = -inf;
	}
	int lim = k - mark[v];
	for(int i = 0;i<(int)vc.size();i++){
		int num = vc[i].first;
		int u = vc[i].second.first ,l = vc[i].second.second;
		for(int i = 0;i<=num;i++)G[i] = -inf;
		getG(u, 0,l,mark[u] );
		if(i){// from other child
			for(int j = 0;j <= lim&& j<=num;j++){
				int rlim = min(lim - j, vc[i-1].first);
				if(F[rlim] == -inf|| G[j] == -inf)continue;
				ans = max(F[rlim] + G[j], ans);
			}
		}
		for(int j = 0 ;j <= num &&j<= lim;j++){//from v to current tree
			F[j] = max(F[j] , G[j]);
			if(j) F[j] = max(F[j] , F[j-1]);
			ans = max(G[j],ans);
		}
	}
	for(auto x : vii[v]){
		int u = x.first;
		if(done[u])continue;
#define initrt(z) root = -1,cntrt = inf,n =z
		initrt(cc[u]);
		getrt(u,0);
		work(root);
	}
}
void inp(){
	MS(mark);MS(done);
	int m;if(scanf("%d%d%d",&n,&k,&m)!=3)exit(0);
	for(int i = 0;i<=n;i++){vii[i].clear();
		vii[i].reserve(10);
	}
	for(int i =0;i<m;i++){
		int x;scanf("%d",&x);
		mark[x] = 1;
	}
	for(int i = 0;i<n - 1;i++){
		int a,b,l;scanf("%d%d%d",&a,&b,&l);
#define vpush(x,y,z) vii[x].push_back(P(y,z))
		vpush(a,b,l);
		vpush(b,a,l);
	}
	initrt(n);
	getrt(1,0);
	ans = 0;
	work(root);
	printf("%d\n", ans);
}
//spoj1825.cc by xsthunder at Fri Jul 28 15:59:55 2017

//AC at Sat Jul 29 17:42:08 2017
 
