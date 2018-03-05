#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 200000+ 100;
int n;
int b[N],a[N],a2[N];
#define lb(v) ((v)&(-v))
void add(int *z,int p,int v){
	for(;p<=n;p+=lb(p)){
		z[p]+=v;
	}
}
int sumb(int l,int r){
	l--;
	int suml = 0;
	for(;l;l-=lb(l)){
		suml += b[l];
	}
	int sumr =0;
	for(;r;r-=lb(r)){
		sumr += b[r];
	}
	return sumr - suml;
}
P P1[N],P2[N];
void suma(int l,int r,int L = 1,int R = n){
	if(l<L || r >R)return 0;
	if(l<=L&&R<=r)return a[i];
	int M = (L+R)>>1;
	return suma(l,r
	return 
}
void inp(){
	scanf("%d",&n);int x;
	for(int i =1 ;i<=n;i++){
		scanf("%d",&x);
		add(b,i,x);
	}
	int q;scanf("%d",&q);
#define X first
#define Y second
	P *p1=P1,*p2=P2;
	for(int i = 0;i<q;i++)scanf("%d%d",&p1[i].X,&p1[i].Y);
	int upd = 1;
	while(upd){
		int tq = 0;
#define suma(z) (z*sum(a,(z)) - sum(a2,(z)))
		for(int i =0;i<q;i++){
			int l = p1[i].X, r = p1[i].Y;
			if(r - l + 1 - sumb(l,r) <= suma(l,r) - sumb(l,r)){
			}
		}
	}
}
//F.cc by xsthunder at Sat Nov 11 21:26:03 2017

