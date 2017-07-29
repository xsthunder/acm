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
typedef vector<P> VI;
typedef vector<VI > VII;
void inp();
int main(){
#ifdef XS
	freopen("poj1741.in","r",stdin);
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
int n,k;
const int N = 1e4 +100;
VII vii(N);
int root ,frt;
int cc[N];
bool done[N];
const int inf = 1e9;
int CNT = 0;
void getrt(int v,int fa){
	cc[v] = 1;int f = -inf;
	for(int i = 0;i<(int)vii[v].size();i++){
		int u = vii[v][i].first;
		if(done[u]||u == fa)continue;
		getrt(u,v);
		cc[v] += cc[u];
		if(cc[u] > f)
			f = cc[u];
	}
	if(n - cc[v] > f)
		f = n - cc[v];
	if(f < frt ){
		frt = f;
		root = v;
	}
}
vector<int > de;
void getde(int rt,int fa,int d){
	de.push_back(d);
	for(int i = 0 ;i<(int)vii[rt].size();i++){
		int u = vii[rt][i].first, l = vii[rt][i].second;
		if(fa == u|| done[u])continue;
		getde(u ,rt, d+l);
	}
}
int calde(int rt ,int l){
	de.clear();
	getde(rt, -1,  l);//finish use for l
	sort(de.begin(),de.end());
	int ans = 0;
	for(int l = 0,r = de.size()-1;l<r;){
		if(de[l] + de[r] <= k)ans += r - l++;
		else r--;
	}
	return ans;
}
#define initrt root = -1,frt = inf
void work(int rt){
	done[rt] = true;
	int ans =  calde(rt, 0);
	for(int i = 0;i<(int) vii[rt].size();i++){
		int u = vii[rt][i].first;int l = vii[rt][i].second;
		if(done[u])continue;
		ans -= calde (u, l);
		initrt; n = cc[u];getrt(u,-1);
		work(root);
	}
	CNT += ans;
}
void inp(){
	scanf("%d%d",&n,&k);
	if(!n&&!k)exit(0);
	CNT = 0;
	MS(done);
	for(int i = 0;i<=n;i++)vii[i].clear();
	for(int i = 1;i<=n-1;i++){
		int a,b,l;scanf("%d%d%d",&a,&b,&l);
#define vpush(x,y,z) vii[x].push_back(P(y,z))
		vpush(a,b,l);
		vpush(b,a,l);
	}
	initrt; getrt(1,-1);
	work(root);
	printf("%d\n",CNT);
}
//poj1741.cc by xsthunder at Thu Jul 27 20:22:01 2017

//AC at Sat Jul 29 15:05:59 2017
 
