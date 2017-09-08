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
	freopen("bzoj1935.in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int Nbit=1e7+1000;
int bit[Nbit];
#define lb(z) ((z)&(-z))
void add(int x,int v){ for(;x<=Nbit;x+=lb(x))bit[x]+=v; }
int que(int x){
	int ans=0;
	for(;x;x-=lb(x)){ ans+=bit[x]; }
	return ans;
}
void clear(int x){
	for(;x<=Nbit;x+=lb(x)){
		if(bit[x])bit[x]=0;
		else break;
	}
}
const int NQ = 30e5;
struct Q{
	int t,x,y,v,aid;
	bool operator <(const Q&r){ return  x==r.x?t<r.t:x<r.x;}
	void add(int t,int x,int y,int v=-0x7fffffff,int aid=-0x7fffffff){
		this->t=t,this->x=x,this->y=y,this->v=v,this->aid=aid;
	}
}qs[NQ],tmp[NQ];
int qcnt=0;
const int N = 5e5+1000;
int ans[N];
void cdq(const int L,const int R){
	if(R-L<=1)return ;
	const int M = (L+R)>>1;cdq(L,M),cdq(M,R);
	int l=L,r=M,o=0;
	while(l<M&&r<R){
		if(qs[l]<qs[r]){
			if(qs[l].t==0)add(qs[l].y,1);
			tmp[o++]=qs[l++];
		}
		else {
			if(qs[r].t==1)ans[qs[r].aid]+=qs[r].v*que(qs[r].y);
			tmp[o++]=qs[r++];
		}
	}
	while(l<M)tmp[o++]=qs[l++];
	while(r<R){
			if(qs[r].t==1)ans[qs[r].aid]+=qs[r].v*que(qs[r].y);
			tmp[o++]=qs[r++];
	}
	for(int i=0;i<o;i++){ clear(tmp[i].y); }
	memcpy(qs+L,tmp,o*sizeof(Q));
}
void inp(){
	int n,m;scanf("%d%d",&n,&m);
	int x,y,x1,y1,ansid=0;qcnt=0;
	for(int i=0;i<n;i++){ scanf("%d%d",&x,&y);x++,y++; qs[qcnt++].add(0,x,y); }
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&x,&y,&x1,&y1);x++,y++,x1++,y1++;
		qs[qcnt++].add(1,x-1,y-1,1,ansid),
			qs[qcnt++].add(1,x-1,y1,-1,ansid),
			qs[qcnt++].add(1,x1,y-1,-1,ansid),
			qs[qcnt++].add(1,x1,y1,1,ansid);
		ansid++;
	}
	cdq(0,qcnt);
	for(int i=0;i<ansid;i++){ printf("%d\n",ans[i]); }
}
//bzoj1935.cc by xsthunder at Fri Sep  8 09:56:51 2017

//AC at Fri Sep  8 11:53:48 2017
 
