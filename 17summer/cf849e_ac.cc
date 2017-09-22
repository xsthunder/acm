#include<cstdio>
#include<cassert>
#include<set>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("cf849e.in","r",stdin);
#endif
	inp();
	return 0;
}
const int N = 1e5+100;
typedef set<int > S;
S s[N];
ll ans[N];
int a[N],qcnt=0;
struct Q{
	int t,x,y,v,aid;//t -> 0 -> modi
	bool operator < (const Q&r){return x==r.x?t<r.t:x<r.x;}
	void mset(int x,int y,int op){ this->t=0,this->x=x,this->y=y;this->v=op*(x-y); }
	void aset(int x,int y,int v,int aid){
		this->t=1,this->x=x,this->y=y,this->v=v,this->aid=aid;
	}
}qs[N*10],tmp[N*10];
S::iterator it;
int fsz(S & s){return s.size();}
void modi(int p,int v){
	//if(!s[v].size()){ s[v].insert(p); a[p]=v; return ; }
	//erase
	int ov=a[p];
	if(ov==v)return;
	a[p]=v;
	int a=0,b=0;
	if(ov){it=s[ov].find(p);assert(it!=s[ov].end());
		if(it!=s[ov].begin()){
			it--;qs[qcnt++].mset(p,a=*it,-1);it++;
		}
		it++;if(it!=s[ov].end()){
			qs[qcnt++].mset(b=*it,p,-1);
		}
		it--;
		s[ov].erase(it);
		if(a&&b)qs[qcnt++].mset(b,a,1);
	}
	//insert
	it=s[v].insert(p).first;
	a=0,b=0;
	if(it!=s[v].begin()){
		it--;qs[qcnt++].mset(p,*it,1),a=*it;it++;
	}
	it++;if(it!=s[v].end()){
		qs[qcnt++].mset(*it,p,1),b=*it;
	}
	it--;
	//cut
	if(a&&b)qs[qcnt++].mset(b,a,-1);
	assert(*it==p);
}
ll bit[N];
#define lb(z) ((z)&(-z))
void add(int p,int v){
	for(;p<=N;p+=lb(p)){ bit[p]+=v; }
}
ll sum(int p){
	ll ans=0;
	for(;p;p-=lb(p)){
		ans+=bit[p];
	}
	return ans;
}
void clr(int p){
	if(!p)return;
	for(;p<=N&&bit[p];p+=lb(p)){
		bit[p]=0;
	}
}
void cdq(const int L,const int R){
	if(R-L<=1)return ;
	int M=(L+R)>>1;
	cdq(L,M);
	cdq(M,R);
	int m=L,r=M,o=0;
	while(m<M&&r<R){
		if(qs[m]<qs[r]){
			if(qs[m].t==0){ add(qs[m].y,qs[m].v); }
			tmp[o++]=qs[m++];
		}
		else {
			if(qs[r].t==1){ ans[qs[r].aid]+=qs[r].v*sum(qs[r].y); }
			tmp[o++]=qs[r++];
		}
	}
	while(m<M){ tmp[o++]=qs[m++]; }
	while(r<R){
			if(qs[r].t==1){ ans[qs[r].aid]+=qs[r].v*sum(qs[r].y); }
			tmp[o++]=qs[r++];
	}
	for(int i=0;i<o;i++){
		qs[L+i]=tmp[i];clr(tmp[i].y);
	}
}
void inp(){
	int n,m;scanf("%d%d",&n,&m);
	int x;for(int i=1;i<=n;i++){scanf("%d",&x);modi(i,x); }
	int op,a,b,ansid=0;
	for(int I=0;I<m;I++){
		scanf("%d%d%d",&op,&a,&b);
		if(op==1){ modi(a,b); }
		else {
			qs[qcnt++].aset(b,b,1,ansid);
			qs[qcnt++].aset(a-1,a-1,1,ansid);
			qs[qcnt++].aset(a-1,b,-1,ansid);
			qs[qcnt++].aset(b,a-1,-1,ansid);
			ansid++;
		}
	}
	cdq(0,qcnt);
	for(int i=0;i<ansid;i++){
		printf("%lld\n",ans[i]);
	}
}
//cf849e.cc by xsthunder at Sat Sep  9 21:35:44 2017

//AC at Tue Sep 12 08:47:30 2017
 
