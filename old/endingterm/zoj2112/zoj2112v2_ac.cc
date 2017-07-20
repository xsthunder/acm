#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
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
const int M = 1e4+100,N = 5e4 +100;
struct Q{
	int i,j,k;
}qus[2*M];
struct T{
	int l,r,v;
}nod[30*(M+N)];
int Mcnt;
void _pcmt(int root,int w,int filter){
	const int f = 15;
	if(!root)return;
	if(filter||root<nod[root].r){
		if(root)_pcmt(nod[root].r, w+f,filter);
	}
	printf("%*sn[%d]l:%dr:%dv:%d\n",w,"",root,nod[root].l,nod[root].r,nod[root].v);
	if(filter||root<nod[root].l){
		if(root)_pcmt(nod[root].l, w+f,filter);
	}
}
void pcmt(const int * rts, int size,int filter = 1,char *s =NULL){//filter = 1 disable filter
	printf("chairmen Tree debug info:%s\n",s);
	for(int i = 1;i<= size;i++){
		printf("root[%d]:-----------\n",i);
		_pcmt(rts[i],0,filter);
	}
}
#define get(ind) nod[ind]
#define mid(l,r) (l+r)/2
#define lb(i) (i&(-i))
int A[M+N],Asize;
int unq[M+N],unqsize;
int srt[N],bitrt[N],n,m;
map<int,int> mp;
int main(){
#ifdef XS
	freopen("zoj2112v2.in","r",stdin);
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
void initunq(int cnt){
	memcpy(unq,A,sizeof(A));
	int *bit = unq + 1;
	int *eit = unq + cnt + 1 ;
	sort(bit,eit);
	eit = unique(bit,eit);
	unqsize = eit - bit ;
	for(int i = 1 ;bit != eit;i++,bit++){
		mp[*bit] = i;
	}
}
void ins(int & root, const int x, const int val, const int Rl ,const int Rr){
	++Mcnt;
	nod[Mcnt] = nod[root];
	root = Mcnt;
	get(root).v+=val;
	if(Rl==Rr)return;
	const int m = mid(Rl, Rr);
	if(x<=m){
		ins(get(root).l,x,val,Rl ,m);
	}
	else {
		ins(get(root).r, x, val, m + 1, Rr);
	}
}
void initsrt(){
	const int  Rl = 1, Rr = unqsize, val = 1;
	for(int i =1 ;i<= n;i++){
		srt[i] = srt[i-1];
		int x = mp[A[i]];
		ins(srt[i],x, val, Rl, Rr);
	}
}
void add(int i,const int x , const int val ){
	const int  Rl = 1, Rr = unqsize;
	for(;i<=n;i+=lb(i))ins(bitrt[i], x, val, Rl , Rr);
}
int ibit[N],jbit[N],ibitsize,jbitsize;
void initque(int i ,int j){
	ibitsize = 0;
	jbitsize = 0 ;
	for(;i>0;i-=lb(i))ibit[++ibitsize] = bitrt[i];
	for(;j>0;j-=lb(j))jbit[++jbitsize] = bitrt[j];
}
int sum(int a[], int size){
	int ans = 0;
	for(int i = 1;i<= size;i++){
		ans += get(get(a[i]).l).v;
	}
	return ans;
}
int que(const int isrt , const int jsrt ,const int Rl ,const int Rr, const int k){
	if(Rl == Rr )return Rl ;
	int diffsrt = get(get(jsrt).l).v - get(get(isrt).l).v;
	int diffbit = sum(jbit , jbitsize ) - sum(ibit,ibitsize);
	int diff = diffsrt + diffbit;
	const int m = mid(Rl ,Rr);
	if( k <= diff){
		for(int i = 1;i<= ibitsize;i++) ibit[i] = get(ibit[i]).l;
		for(int j = 1;j<= jbitsize;j++) jbit[j] = get(jbit[j]).l;
		return que(get(isrt).l, get(jsrt).l, Rl ,m ,k); 
	}
	else {
		for(int i = 1;i<= ibitsize;i++) ibit[i] = get(ibit[i]).r;
		for(int j = 1;j<= jbitsize;j++) jbit[j] = get(jbit[j]).r;
		return que(get(isrt).r, get(jsrt).r, m+1 ,Rr,k - diff); 
	}
}
void start(){
	const int  Rl = 1, Rr = unqsize;
	for(int i = 1; i<= m;i++){
		const Q q = qus[i];
		if(q.k){
			initque(q.i-1,q.j);
			int ans = que(srt[q.i - 1] ,srt[q.j],Rl ,Rr, q.k);
			printf("%d\n", unq[ans]);
		}
		else {
			add(q.i,mp[A[q.i]], -1 );
			A[q.i]=q.j;
			add(q.i,mp[q.j], 1 );
		}
	}

}
void inp(){
	mp.clear();
	MS(nod);MS(srt);
	MS(bitrt);
	Mcnt = 0;
	scanf("%d%d", &n,&m);
	int cnt = 0;
	for(int i =0;i<n;i++){
		scanf("%d", &A[++cnt]);//A from 1
	}
	for(int i = 1;i<=m;i++){
		char s[10];scanf("%s",s);
		Q &q = qus[i];
		if(s[0]=='Q')scanf("%d%d%d", &q.i,&q.j,&q.k);
		else {
			q.k=0;scanf("%d%d", &q.i, &q.j);
			A[++cnt]=q.j;
		}
	}
	initunq(cnt);
	initsrt();
	start();
#ifdef XS
	pcmt(bitrt,n, 1);
#endif
}
//zoj2112v2.cc by xsthunder at Tue Jul 18 14:23:53 2017

//AC at Wed Jul 19 15:08:51 2017
 
