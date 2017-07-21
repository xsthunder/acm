#include<cstdio>
#include<algorithm>
#include<map>
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
	freopen("bzoj2809.in","r",stdin);
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
const int N = 1e5 +100;
P A[N];
struct T{
	int cnt;ll sum;
	int l,r;
}nod[30*N];
typedef vector<int > VI;
typedef vector<VI > VII;
VII vii(N);
int p1[N], p2[N];
int ti = 0,Mcnt = 0;
void dfs(int u ,int fa){
	p1[u] = ++ti;
	for(VI::iterator it = vii[u].begin();it != vii[u].end();it++){
		if(*it == fa)continue;
		dfs(*it, u);
	}
	p2[u] =ti;
}
int unq[N],C[N],unqsize;
map<int ,int>mp;
int root[N];
void initunq(const int n ){
	for(int i = 1;i<=n;i++){
		unq[i] = A[i].first;
	}
	int *bit = unq+1;
	int * eit = unq +n +1;
	sort(bit,eit);
	eit = unique(bit,eit);
	for(unqsize = 0 ;bit!=eit ;bit++){
		mp[*bit] = ++unqsize;
	}
	for(int i = 1;i<=n;i++){
		C[p1[i]] = A[i].first;
	}
}
void ins(const int val ,const int x, int &root, const int L,const int R){
#define mid int m = (L+R)/2
#define pl L  ,m
#define pr m+1,R
#define lson(x) nod[x].l
#define rson(x) nod[x].r
#define pushup(x) nod[x].cnt =nod[lson(x)].cnt+nod[rson(x)].cnt, nod[x].sum = nod[lson(x)].sum+nod[rson(x)].sum;
	nod[++Mcnt] = nod[root];
	root = Mcnt;
	if(L == R){
		nod[root].sum += val;
		nod[root].cnt += 1;
		return;
	}
	mid;
	if(x<=m)ins(val,x,lson(root),pl);
	else ins(val,x,rson(root),pr);
	pushup(root)
}
void initct(const int n){
	for(int i = 1;i<=n;i++){
		root[i] = root[i-1];
		ins(C[i], mp[C[i]], root[i], 1, unqsize);
	}
}
ll que(const int lrt, const int rrt ,int bud, const int L,const int R){
	if(nod[rrt].sum - nod[lrt].sum <= bud){
		return nod[rrt].cnt - nod[lrt].cnt;
	}
	else if( L == R){
		ll single = (nod[rrt].sum-nod[lrt].sum)/(nod[rrt].cnt-nod[lrt].cnt);
		return bud / single;
	}
	ll diff = nod[lson(rrt)].sum - nod[lson(lrt)].sum ; 
	ll ans = 0;
	mid;
	if(diff <= bud){
		ans += nod[lson(rrt)].cnt - nod[lson(lrt)].cnt;
		bud -= diff;
	}
	else {
		return que(lson(lrt), lson(rrt), bud, pl);
	}
	if(bud)
		ans += que(rson(lrt), rson(rrt), bud, pr);
	return ans ;
}
ll start(const int n,const int bud){
	ll ans = 0;
	for(int i = 1;i<=n;i++){
		ll qu = que(root[p1[i] - 1], root[p2[i]], bud ,1,unqsize);
		qu *= A[i].second;
		if(qu >ans)
			ans = qu;
	}
	return ans;
}
void inp(){
	int bud,n;
	int head = 0;
	scanf("%d%d",&n, &bud);
	for(int i =1; i<= n;i++){
		int a = i,b,c,l;
		scanf("%d%d%d",&b,&c,&l);
#define vpush(a,b) vii[a].push_back(b);
		if(b==0){ head = i; }
		else {
			vpush(a,b);
			vpush(b,a);
		}
		A[i].first = c;A[i].second = l;
	}
	dfs(head , -1);
	initunq(n);
	initct(n);
	printf("%lld\n",start(n,bud));
}
//bzoj2809.cc by xsthunder at Fri Jul 21 10:32:49 2017

//AC at Fri Jul 21 15:51:43 2017
 
