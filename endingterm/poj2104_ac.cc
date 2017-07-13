#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	const int Te=1;
#include<De>
#else 
	const int Te=0;
#endif
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
	//freopen("poj2104.in","r",stdin);
	try{
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 1e5+1e4;
int a[N];
int root[N];
int unq[N];
int Mcnt=0;
struct T{
	int lch,rch;
	int cnt;
}nod[20*N];
#define jsOr(x,y) (x?x:y) 
void add(T &curT ,const int val, const int L,const int R){
	//if(val<L||val>R)return ;
	curT.cnt++;
	if(L==R) return ;
	const int mid = (L+R)/2;
	int sou = curT.lch;
	if(val>mid)sou =curT.rch;
	const int nxt  = Mcnt++;
	T &nxtT = nod[nxt];
	nxtT = nod[sou];//copy
	if(val>mid){
		curT.rch =nxt;
		add(nxtT,val,mid+1,R);
	}
	else {
		curT.lch = nxt;
		add(nxtT, val, L,mid);
	}
}
int que(const T TL,const T TR,const int k,const int L,const int R){
	int cnt = nod[TR.lch].cnt- nod[TL.lch].cnt;
	const int mid = (L+R)/2;
	if(L==R)return L;
	if(k<=cnt){//left tree
		return que(nod[TL.lch],nod[TR.lch],k,L,mid);
	}
	else {
		return que(nod[TL.rch],nod[TR.rch],k-cnt,mid+1,R);
	}
}
void inp(){
	int n,m;
	scanf("%d%d", &n,&m);
	root[0]=0;
	nod[0].lch=nod[0].rch=nod[0].cnt=0;
	Mcnt=1;
	for(int i=1;i<=n;i++){
		scanf("%d",& a[i]);
	}
	memcpy(unq,a,sizeof(a));
	int *unqbit = unq+1;
	int *unqeit = unq+n+1;
	sort(unqbit,unqeit);
	unqeit = unique(unqbit,unqeit);
	
	const int L = 1;
	const int R = n;
	for(int i =1;i<=n;i++){
		int nxt = Mcnt++;
		int val = lower_bound(unqbit,unqeit,a[i])-unqbit+1;
		//printf("que hash(%d) = %d\n",a[i],val);
		root[i]=nxt;
		T &curT = nod[nxt];
		curT=nod[root[i-1]];//copy the i-1th
		add(curT,val,L,R);
	}
	//pA(root, n+1);
	while(m--){
		int l,r,k;
		scanf("%d%d%d", &l,&r,&k);
		int ind = (que(nod[root[l-1]],nod[root[r]],k,L,R));
		printf("%d\n", unq[ind]);
	}
}
//poj2104.cc by xsthunder at Tue Jul 11 10:51:50 2017

//AC at Tue Jul 11 15:29:41 2017
 
