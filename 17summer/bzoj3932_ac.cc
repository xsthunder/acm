#include<cstdio>
#include<queue>
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
	freopen("bzoj3932.in","r",stdin);
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
const int N = 1e5 + 1000;
int unq[N];
typedef vector<P > VI;
typedef vector<VI> VII;
VII vii(N);
map<int ,int > mp;
void initunq(int &unqsize){
	int * bit = unq + 1 ;
	int * eit = unq + unqsize +1;
	sort(bit, eit);
	eit = unique(bit, eit);
	for(unqsize = 0;bit!=eit ; bit++){
		mp[*bit] = ++unqsize;
	}
}
int root[N];
struct T{
	ll sum;
	int cnt,l,r;
}nod[50*N];
int Mcnt = 0;
void ins(int &rt, const int x , const int val , const int L,const int R){
#define mid int m = (L+R)/2
#define pl L  ,m
#define pr m+1,R
#define lson(x) nod[x].l
#define rson(x) nod[x].r
#define sum(x) nod[x].sum
#define cnt(x) nod[x].cnt
#define pushup(x) sum(x) = sum(lson(x)) + sum(rson(x)),cnt(x) = cnt(lson(x))+ cnt(rson(x))
	Mcnt++; nod[Mcnt] = nod[rt]; rt = Mcnt;
	if(L==R){
		cnt(rt) += val;
		sum(rt) += val*unq[L];
		return;
	}
	mid;
	if(x<=m)ins(lson(rt), x, val, pl);
	else ins(rson(rt), x, val, pr);
	pushup(rt);
}
void initrt(const int n,const int unqsize){
	priority_queue<P,vector<P > , greater<P > > pq;
	for(int i = 1;i<=n;i++){
		root[i] = root[i-1];
		while(!pq.empty()&&pq.top().first < i){
			P p = pq.top();pq.pop();
			ins(root[i], mp[p.second], -1, 1,unqsize);
		}
		for(VI::iterator it = vii[i].begin(); it!= vii[i].end();it++){
			P p = *it;
			ins(root[i], mp[p.second], 1, 1, unqsize);
			pq.push(p);
		}
	}
}
ll que(const int rt, int k ,const int L,const int R){
	if(cnt(rt) <= k){
		return sum(rt);
	}
	else if( L == R){
		return k * (sum(rt)/cnt(rt));
	}
	mid;
	ll ans = 0;
	if(cnt(lson(rt)) <= k){
		ans += sum(lson(rt));
		k -= cnt(lson(rt));
	}
	else {
		return que(lson(rt), k ,pl);
	}
	if(k){
		ans += que(rson(rt), k ,pr);
	}
	return ans;
}
void start(const int m,const int unqsize){
	ll pre = 1;
	for(int i = 1;i<= m;i++){
		ll x,a,b,c;
		scanf("%lld%lld%lld%lld",&x, &a, &b,&c);
		ll k = 1 + (a * pre + b) %c;
		ll ans = que(root[x], k, 1, unqsize);
		pre = ans;
		printf("%lld\n",ans);
	}
}
void pcmt(int rt,int w = 0){
	const int f = 5;
	if(rson(rt)){
		pcmt(rson(rt), w+f);
	}
	printf("%*snod[%d]:l:%d,r:%d,s:%lld,c:%d\n",w, "",rt, nod[rt].l,nod[rt].r,sum(rt), cnt(rt));
	if(lson(rt)){
		pcmt(lson(rt),w+f);
	}
}
void inp(){
	int m,n;scanf("%d%d",&m,&n);
	int unqsize = 0;
	for(int i = 1 ;i<=m;i++){
		int s,e,p;scanf("%d%d%d", &s, &e,&p);
		unq[++unqsize] = p;
		vii[s].push_back(P(e,p));
	}
	initunq(unqsize);
	initrt(n,unqsize);
	start(n,unqsize);//n -> m
#ifdef XS
	for(int i =1;i<=n;i++){
		printf("root(%d)----------------\n",i);
		pcmt(root[i]);
	}
#endif
}
//bzoj3932.cc by xsthunder at Fri Jul 21 19:59:36 2017

//AC at Fri Jul 21 21:03:03 2017
 
