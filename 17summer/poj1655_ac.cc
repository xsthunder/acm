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
	freopen("poj1655.in","r",stdin);
#endif
	try{
		int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
int n;
typedef vector<int > VI;
typedef vector<VI > VII;
VII vii;
const int N = 2e4 +100;
int ma[N];
int cnt[N];
void dfs(int v,int fa){
	for(int i = 0;i<(int )vii[v].size();i++){
		if(vii[v][i] == fa)continue;
		int x = vii[v][i];
		dfs(x, v);
		cnt[v] += cnt[x];
		if(ma[v] < cnt[x])
			ma[v] = cnt[x];
	}
	cnt[v]++;
	int up = n - cnt[v];
	if(ma[v] < up)
		ma[v] = up;
}
void inp(){
	MS(ma);MS(cnt);
	scanf("%d",&n);
	vii.clear();vii.resize(n+2);
	for(int i = 1;i<=n-1;i++){
		int a,b;scanf("%d%d",&a,&b);
#define vpush(x,y) vii[x].push_back(y)
		vpush(a,b);
		vpush(b,a);
	}
	dfs(1,-1);
	int ans = ma[1];
	int ind = 1;
	for(int i = 1;i<=n;i++){
		if(ans > ma[i]){
			ind = i;
			ans = ma[i];
		}
	}
	printf("%d %d\n",ind,ans);
}
//poj1655.cc by xsthunder at Thu Jul 27 09:59:09 2017

//AC at Thu Jul 27 10:16:28 2017
 
