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
	freopen("poj3321.in.max","r",stdin);
#endif
	try{
		//while(1)
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
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
typedef vector<int > VI;
VI vi[N];
int p1[N];
int p2[N];
int ti = 0;
void dfs(int u, int fa ){
	p1[u] = ++ti;
	for(VI::iterator it = vi[u].begin();it!= vi[u].end();it++){
		if(*it==fa)continue;
		dfs(*it,u);
	}
	p2[u] = ti;
}
#define mid (L+R)/2
#define get(x) nod[x]
struct T{
	int l,r,sum;
}nod[4*N];
const int root = 1;
void bui(const int rt, const int L,const int R){
	get(rt).l = L;
	get(rt).r = R;
	if(L == R){
		get(rt).sum =  1;
		return;
	}
#define lson (rt*2)
#define rson (rt*2+1)
#define pushup get(rt).sum = get(lson).sum + get(rson).sum ;
	int m = mid;
	bui(lson,L  ,m);
	bui(rson,m+1,R);
	pushup
}
void upd(const int rt,const int a){
	int R = get(rt).r;
	int L = get(rt).l;
	if(R==L){
		get(rt).sum ^= 1;
		return ;
	}
	int m = mid;
	if(a<=m){
		upd(lson, a);
	}
	else upd(rson,a);
	pushup;
	return;
}
int que(const int rt,const int l,const int r){
	const int R = get(rt).r,L = get(rt).l;
	const int m = mid;
	if(r<L || R < l)return 0;
	if(l <=L && R <= r){
		return get(rt).sum;
	}
	int ans1 = que(lson , l, r);
	int ans2 = que(rson , l, r);
	return ans1+ans2;
}
void inp(){
	int n ,m;
	scanf("%d",&n);
	for(int i = 1 ;i< n;i++){
		int a,b;
		scanf("%d%d", &a,&b);
#define vpush(a,b) vi[a].push_back(b)
		vpush(a,b);
		vpush(b,a);
	}
	dfs(1, -1);
	bui(root,1,n);
	scanf("%d",&m);
#ifdef XS
	//	pA(p1,n+1,"p1");
//	pA(p2,n+1,"p2");
	
#endif
	while(m--){
		char s[5] ;
		int a;
		scanf("%s%d", s,&a );
		if(s[0] == 'C')upd(root,p1[a]);
		else printf("%d\n", que(root, p1[a],p2[a]));
	}
}
//poj3321.cc by xsthunder at Wed Jul 19 19:57:34 2017

