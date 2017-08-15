#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("at80c.in","r",stdin);
#endif
	inp();
	return 0;
}
const int N = 2e5+100;
struct Tt{ int v,id; };
bool operator < (Tt a,Tt b){return a.v<b.v;}
typedef pair<Tt,P> PP;
priority_queue<PP,vector<PP> ,greater<PP>> pq;
Tt To[N*4],Te[N*4];
int A[N];
#define lson (rt<<1)
#define rson ((rt<<1)+1)
#define mid int m = (L+R)>>1;
#define pl lson,L,m
#define pr rson,m+1,R
const int inf = 0x7fffffff;
void bui(Tt *T,int t,int rt,int L,int R){
	if(L==R){ T[rt].id=L,T[rt].v=(L&1)==t?A[L]:inf; return; }
	mid;
	bui(T,t,pl);
	bui(T,t,pr);
#define pushup T[rt]=min(T[lson],T[rson])
	pushup;
}
void rem(Tt *T,int l,int rt,int L,int R){
	if(L==R){
		T[rt].v=inf;
		return;
	}
	mid;
	if(l<=m){ rem(T,l,pl); }
	else if(l>m){ rem(T,l,pr); }
	pushup;
}
#define que(T,l,r,rt,L,R) __que(((l)&1)?To:Te,(l),r,rt,L,R)
Tt __que(Tt *T,int l,int r,int rt,int L,int R){
	if(l<=L&&R<=r)return T[rt];
	if(r<L||R<l){Tt ans;ans.id=-1,ans.v=inf;return ans;}
	mid;
	return min(__que(T,l,r,pl),__que(T,l,r,pr));
}
void inp(){
	int n;scanf("%d",&n);
	for(int i =1;i<=n;i++)scanf("%d",&A[i]);
	bui(To,1,1,1,n);bui(Te,0,1,1,n);
	PP pp(que(To,1,n,1,1,n),P(1,n));
	pq.push(pp);
	PP nx;
	while(!pq.empty()){
		pp = pq.top();pq.pop();
		Tt tt= que(Te,pp.first.id+1,pp.second.second,1,1,n);
		rem(To,pp.first.id,1,1,n);
		rem(Te,tt.id,1,1,n);
		printf("%d %d ",pp.first.v,tt.v );
		if(pp.first.id!=pp.second.first){
			nx.second.first=pp.second.first;
			nx.second.second=pp.first.id-1;
			nx.first=que(To,nx.second.first,nx.second.second,1,1,n);
			pq.push(nx);
		}
		if(pp.first.id!=tt.id-1){
			nx.second.first=pp.first.id+1;
			nx.second.second=tt.id-1;
			nx.first=que(To,nx.second.first,nx.second.second,1,1,n);
			pq.push(nx);
		}
		if(tt.id!=pp.second.second){
			nx.second.first=tt.id+1;
			nx.second.second=pp.second.second;
			nx.first=que(To,nx.second.first,nx.second.second,1,1,n);
			pq.push(nx);
		}
	}
}
//at80c.cc by xsthunder at Wed Aug  9 22:03:34 2017

//AC at Thu Aug 10 08:46:30 2017
 
