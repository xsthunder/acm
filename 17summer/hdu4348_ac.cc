#include<cstdio>
#include<algorithm>
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
	freopen("hdu4348.in","r",stdin);
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
const int N = 1e5 +100;
//int A[N];
int root[N];
struct T{
	int l,r;ll sum,c;
}nod[27*N];
int Mcnt;
void init(int & rt,const int L,const int R){
#define mid int m = (L+R)/2
#define lson(z) nod[z].l
#define rson(z) nod[z].r
#define pl L  ,m
#define pr m+1,R
#define allc(z) ++Mcnt,nod[Mcnt] = nod[z],z = Mcnt
#define sum(z) nod[z].sum
#define c(z) nod[z].c
#define pushup(z) sum(lson(z)) + sum(rson(z))
#define maskque(z) c(z)*(min(R,r)-max(L,l)+1)
#define maskadd(z) c(z)*(R - L + 1)
	allc(rt);
	if(L == R){
		scanf("%lld",&sum(rt));
		return;
	}
	mid;
	init(lson(rt), pl);
	init(rson(rt), pr);
	sum(rt) = pushup(rt);
}
void add(const int l,const int r,ll d, int &rt,const int L,const int R){
	if( r<L || R < l)return;
	allc(rt);
	if( l<= L&&R<=r){
		sum(rt)+=(R - L + 1)*d;
		c(rt) += d;
		return;
	}
	mid;
	add(l,r,d,lson(rt), pl);
	add(l,r,d,rson(rt), pr);
	sum(rt) = pushup(rt) + maskadd(rt);
}
ll que(const int l,const int r,const int rt,const int L,const int R){
	if( r<L || R<l)return 0;
	if(l <= L && R <=r){
		return sum(rt);
	}
	ll ans = 0;
	mid;
	ans += que(l, r, lson(rt), pl);
	ans += que(l, r, rson(rt), pr);
	ans += maskque(rt);
	return ans;
}
void pcmt(int rt, int w=0){
	int f=5;
	if(rson(rt))pcmt(rson(rt),w+f);
	printf("%*sn[%2d],l:%2d,r:%2d,c:%2lld,sum%2lld\n",w,"",rt,lson(rt),rson(rt),c(rt),sum(rt));
	if(lson(rt))pcmt(lson(rt),w+f);
}
void start(const int n,const int m){
	int current = 0;
	char s[4];
	for(int i = 1;i<=m;i++){
		scanf("%s", s);
		switch(s[0]){
			case 'B':
				{ int t;scanf("%d",&t);
					//if(t<current&&root[t+1])Mcnt = root[t+1];
					current = t; }
				break;
			case 'C':
				{ int l,r,d;scanf("%d%d%d", &l,&r,&d);
				root[current + 1] = root[current];
				add(l,r,d,root[++current], 1, n); }
				break;
			case 'H':
				{int l,r,t;scanf("%d%d%d", &l,&r,&t);
				ll ans = que(l,r,root[t],1,n);
				printf("%lld\n",ans); }
				break;
			case 'Q':
				{ int l,r;scanf("%d%d",&l,&r);
				ll ans = que(l,r,root[current],1,n); 
				printf("%lld\n",ans); }
				break;
		}
#ifdef XS
		printf("i:%d of %d\n",i,m);
		for(int i = 0;i<=current;i++){
			printf("root[%d]-----------\n",i);
			pcmt(root[i]);
		}
#endif
	}
}
void inp(){
	//while(1);
	int n,m;
	MS(nod);Mcnt = 0; MS(root);
	if(!~scanf("%d%d",&n,&m))exit(0);
//	for(int i =1;i<=n;i++){ scanf("%d",&A[i]); }
	init(root[0], 1, n);
	start(n,m);
//	printf("\n");
}
//hdu4348.cc by xsthunder at Sat Jul 22 08:37:34 2017

//AC at Mon Jul 24 06:05:04 2017
 
