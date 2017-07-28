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
	freopen("hdu4607.in","r",stdin);
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
typedef vector<int> VI;
typedef vector<VI> VII;
VII vii;
const int N = 1e5+100;
int root;int drt;int d[N];
void dfs(int v,int fa){
	d[v] = d[fa] +1;//父亲进来的，从上而下放在循环前
	for(auto x:vii[v]){
		if(x == fa)continue;
		dfs(x,v);
	}
	if(d[v] > drt ){
		drt = d[v];
		root = v;
	}
}
void inp(){
	int n,m;scanf("%d%d",&n,&m);
	vii.clear();vii.resize(n+1);
	for(int i = 1;i<=n-1;i++){
#define vpush(a,b) vii[a].push_back(b)
		int x,y;scanf("%d%d",&x,&y);
		vpush(x,y);
		vpush(y,x);
	}
	d[0]=-1;
	root = -2;drt = -1;
	dfs(1,0);//注意使用了fa，做数组下标,需要不越界
	drt = -1;
	dfs(root,0);
//	printf("%d %d\n", root ,drt);
	int cnt = drt +1;
	for(int i = 1 ;i<=m;i++){
		int q;scanf("%d",&q);
		if(q <= cnt)printf("%d\n", q-1);
		else printf("%d\n", drt + (q - cnt)*2);
	}
}
//hdu4607.cc by xsthunder at Fri Jul 28 09:47:35 2017

//AC at Fri Jul 28 10:57:36 2017
 
