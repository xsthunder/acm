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
	freopen("cf620E.in","r",stdin);
#endif
	try{
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 4e5  + 100;
ll c[4*N];
ll s[4*N];
ll A[N];
int p1[N],p2[N],mp[N];
int ti = 0;
typedef vector<int > VI;
typedef vector<VI> VII;
VII vii(N);
#define tra(x) (1LL<<(x-1))
void dfs(int u,int fa){
	p1[u] = ++ti;
	for(VI::iterator it  = vii[u].begin();it!= vii[u].end();it++){
		if(*it==fa)continue;
		dfs(*it, u);
	}
	p2[u] = ti;
}
void bui(const int rt, const int L , const int R){
#define mid int m = (L+R)/2
#define lson rt*2
#define rson rt*2+1
#define plson lson,L  ,m
#define prson rson,m+1,R
	if(L==R){
		s[rt] = c[rt] = A[mp[L]];
		return;
	}
	mid;
	c[rt] = 0;
	bui(plson);
	bui(prson);
	if(c[lson] == c[rson])c[rt]=c[lson];
	s[rt] = s[lson]|s[rson];
}
void upd(const int p1 ,const int p2 ,const ll tar,const int rt,const int L,const int R){
	if(p1<= L&&R <=p2){
		s[rt] = c[rt] = tar;
		return ;
	}
	if(p2 < L || R < p1)return;
	mid;
	if(c[rt]){
		s[lson] = c[lson] = c[rt];
		s[rson] = c[rson] = c[rt];
	}
	c[rt] = 0;
	s[rt] = 0;
	upd(p1,p2,tar,plson);
	upd(p1,p2,tar,prson);
	if(c[lson] == c[rson])c[rt]=c[lson];
	s[rt] = s[lson]|s[rson];
}
ll que(const int p1,const int p2 , const int rt,const int L,const int R){
	if(p1<=L && R<= p2 ){
		return s[rt];
	}
	if(p2 < L|| R < p1)return 0;
	ll ans = 0;
	mid;
	if(c[rt]){
		s[lson] = c[lson] = c[rt];
		s[rson] = c[rson] = c[rt];
	}
	ans |= que(p1, p2, plson);
	ans |= que(p1, p2, prson);
	return ans;
}
int cnt (ll x){
	int ans =0 ;
	while(x){
		if(x&1)ans++;
		x>>= 1;
	}
	return ans;
}
void inp(){
	int n,q;scanf("%d%d",&n,&q);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&A[i]);
		A[i] = tra(A[i]);
	}
	for(int i = 1;i<n;i++){
		int a,b;scanf("%d%d", &a,&b);
#define vpush(a,b) vii[a].push_back(b)
		vpush(a,b);
		vpush(b,a);
	}
	dfs(1,-1);
	for(int i = 1;i<=n;i++){ mp[p1[i]] = i; }
	const int root = 1;
	bui(root,1,n);
	while(q--){
		int opt,a,b;scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&a,&b);
			upd(p1[a], p2[a], tra(b),root, 1, n);
		}
		else {
			scanf("%d",&a);
			ll ans = que(p1[a], p2[a], root, 1, n);
			printf("%d\n", cnt(ans));
		}
	}
}
//cf620E.cc by xsthunder at Thu Jul 20 16:59:34 2017
//what?

//AC at Fri Jul 21 09:07:52 2017
 
