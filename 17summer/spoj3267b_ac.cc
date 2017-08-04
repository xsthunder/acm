#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("spoj3267b.in","r",stdin);
#endif
	//while(1)
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int N = 300000+10;
const int A = 1000000+100;
struct Nod{
	int v,l,r;
}T[30*N];
int root[N],rec[A],tcnt=1;
#define mid int m = (L+R)>>1;
#define allc(z) T[tcnt]=T[rt],rt=tcnt,tcnt++
#define lson(z) T[z].l
#define rson(z) T[z].r
#define pushup(z) T[z].v=T[lson(z)].v+T[rson(z)].v
#define pl L,m
#define pr m+1,R
void ad(int p,int v,int &rt,int L,int R){
	allc(rt);
	mid;
	if(L==R){
		T[rt].v+=v;
		return;
	}
	if(p<=m)ad(p,v,lson(rt),pl);
	else ad(p,v,rson(rt),pr);
	pushup(rt);
}
int que(int l,int r,int rt,int L,int R){
	mid;
	int ans=0;
	if(l<=L&&R<=r){
		return T[rt].v;
	}
	if(r<L||R<l)return 0;
	ans+=que(l,r,lson(rt),pl)+
		que(l,r,rson(rt),pr);
	return ans;
}
void pcmt(int rt,int w = 0){
	int f = 4;
	if(rson(rt))pcmt(rson(rt),w+f);
	printf("%*srt:%d,l:%d,r:%d,v:%d\n",w,"",rt,T[rt].l,T[rt].r,T[rt].v);
	if(lson(rt))pcmt(lson(rt),w+f);
}
void inp(){
	int n,x,q,a,b,i;MS(rec,-1);
	for(scanf("%d",&n),i=1;i<=n;i++){
		root[i]=root[i-1];//调用前复制前一个树根
		scanf("%d",&x);
		if(rec[x]==-1);
		else ad(rec[x],-1,root[i],1,n);
		rec[x]=i;
		ad(i,1,root[i],1,n);//在位置插入，值在rec处理
#ifdef XS
		printf("----%dvvvvv\n",i);
		pcmt(root[i]);
#endif
	}
	for(scanf("%d",&q),i=1;i<=q;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",que(a,b,root[b],1,n));
	}
}
//spoj3267b.cc by xsthunder at Fri Aug  4 21:38:08 2017

//AC at Fri Aug  4 22:32:19 2017
 
