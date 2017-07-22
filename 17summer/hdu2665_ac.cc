#include<algorithm>
#include<iostream>
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
int main(){
#ifdef XS
	freopen("hdu2665.in","r",stdin);
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
const int N  = 1e5 + 1e3;
struct T{
	int l,r,v;
}nod[20*N];
int A[N];
int unq[N],unqsize;
int n;
int rt[N],Mcnt;
map<int ,int > mp;
void initunq(){
	memcpy(unq,A,sizeof(A));
	int * bit = unq + 1;
	int * eit = unq + n + 1;
	sort(bit,eit);
	eit = unique(bit,eit);
	unqsize = eit - bit;
	mp.clear();
	for(int i = 1; bit != eit ;i++, bit++){
		mp[*bit] = i;
	}
}
#define mid (rl + rr)/2
#define get(ind) nod[ind]
void ins(int & root , const int x, const int rl,const int rr,const int val){
	Mcnt++ ;
	nod[Mcnt] = nod[root];
	root = Mcnt;
	get(root).v += val;
	if(rl == rr)return;
	int m = mid;
	if(x <=m ) ins(get(root).l, x, rl, m , val);
	else ins(get(root).r, x, m + 1, rr, val);
}
void initrt(){
	Mcnt = 0;
	const int rr = unqsize, rl = 1, val = 1;
	for(int i = 1; i<= n;i++){
		rt[i] = rt[i-1];
		int x = mp[A[i]];
		ins(rt[i] ,x , rl, rr ,val);
	}
}
int que(int art, int brt ,int k ,const int rl,const int rr){
	if(rl == rr)return rl;
	int m = mid;
	int ans = get(get(brt).l).v - get(get(art).l).v;
	if(k <= ans)return que(get(art).l, get(brt).l , k , rl, m);
	else return que(get(art).r, get(brt).r, k - ans , m + 1, rr);
}
void pcmt(int rt,int w = 0){
	if(get(rt).r>rt)pcmt(get(rt).r, w+10);
	printf("%*sn[%d]l:%dr:%dx:%d\n", w,"", rt,get(rt).l,get(rt).r,get(rt).v);
	if(get(rt).l>rt)pcmt(get(rt).l, w+10);
}
void inp(){
	int m ;
	scanf("%d%d", &n, &m);
	for(int i =1;i<=n;i++){
		scanf("%d", &A[i]);
	}
	initunq();
	initrt();
	const int rl = 1,rr = unqsize;
#ifdef XS
	pA(A,n+1,"A");
	pA(unq, rr+1, "unq");
	for(int i = 1;i<= n;i++){
		printf("rt[%d]------------\n",i);
		pcmt(rt[i]);
	}
#endif
	while(m--){
		int a,b,c;scanf("%d%d%d", &a,&b,&c);
		a--;
		int ans = que(rt[a],rt[b],c,rl ,rr);
		printf("%d\n" , unq[ans]);
	}

}
//hdu2665.cc by xsthunder at Tue Jul 18 20:36:44 2017

//AC at Tue Jul 18 21:20:29 2017
 
