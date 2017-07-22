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
	freopen("poj3887.in","r",stdin);
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
const int N = 1e5 + 100;
int p1[N];
int p2[N];
typedef vector<int > VI;
typedef vector<VI> VVI;
VVI vvi(N);
int ti;
void dfs(const int u,const int fa){
	p1[u] = ++ti;
	for(VI::iterator it = vvi[u].begin();it!=vvi[u].end();it++){
		if(*it==fa)continue;
		dfs(*it,u);
	}
	p2[u] = ti;
}
int ma[4*N];
int mi[4*N];
int mp[N];
#define mid int m = (L+R)/2
#define plson rt*2,  L  ,m
#define prson rt*2+1,m+1,R
#define lson rt*2
#define rson rt*2+1
void bui(const int rt, const int L,const int R){
	if(L==R){
		mi[rt] = ma[rt] = mp[L];
		return;
	}
	mid;
	bui(plson);
	bui(prson);
	mi[rt] = min(mi[lson],mi[rson]);
	ma[rt] = max(ma[lson],ma[rson]);
}
int que(const int p1,const int p2,const int i,const int rt,const int L,const int R){
	if(mi[rt]>=i)return 0;
	if(p1<=L&&R<=p2){
		if(ma[rt]<i)return R-L+1;
	}
	if(p1>R||p2<L)return 0;
	int ans = 0;
	mid;
	ans += que(p1,p2,i,plson);
	ans += que(p1,p2,i,prson);
	return ans;
}
void inp(){
	int n,p;
	ti = 0;
	MS(p1);MS(p2);MS(ma);MS(mp);
	scanf("%d%d", &n,&p);
	if(!n&&!p)exit(0);
	for(int i = 1;i<=n;i++){
		vvi[i].clear();
	}
	for(int i = 1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
#define vpush(a,b) vvi[a].push_back(b)
		vpush(a,b);
		vpush(b,a);
	}
	dfs(p,-1);
	for(int i =1;i<=n;i++){
		mp[p1[i]] = i;
	}
	bui(1,1,n);
	for(int i = 1;i<=n;i++){
		int ans = que(p1[i],p2[i],i,1,1,n);
		if(i!=1)printf(" ");
		printf("%d",ans);
	}
	printf("\n");
}
//poj3887.cc by xsthunder at Thu Jul 20 15:20:52 2017

//AC at Thu Jul 20 16:18:37 2017
 
