#include<cstdio>
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
	freopen("hdu1520.in","r",stdin);
#endif
	try{
		while(1)inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 6e3+ 100;
int w[N];
int out[N];
typedef vector<int > VI;
typedef vector<VI > VII;
VII vii;
int dp[N][2];
void dfs(int v,int fa){
	for(auto x:vii[v]){
		if(x == fa)continue;
		dfs(x,v);
		dp[v][0] += max(dp[x][0],dp[x][1]);
		dp[v][1] += dp[x][0] ;
	}
	dp[v][1] += w[v];
//	if(dp[v][1] <0)
//		dp[v][1]=0;
}
void inp(){
	int n;if(scanf("%d",&n)==EOF)exit(0);
	if(!n)exit(0);
	MS(out);MS(w);MS(dp);
	vii.clear();
	vii.resize(n+3);
	for(int i = 1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	int l,k;
	while(scanf("%d%d",&l,&k)!=EOF&&l&&k){
#define vpush(a,b) vii[a].push_back(b);
		vpush(l,k);
		vpush(k,l);
		out[k]++;
	}
	int root = -2;
	for(int i = 1;i<=n;i++)if(out[i] == 0){ root = i;break; }
	dfs(root , -1);
	printf("%d\n",max(dp[root][0], dp[root][1]));
}
//hdu1520.cc by xsthunder at Thu Jul 27 08:45:28 2017

//AC at Thu Jul 27 09:23:32 2017
 
