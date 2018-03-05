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
	freopen("p3374_cdq.in","r",stdin);
#endif
	inp();
	return 0;
}
const int N3 = 15e5+1000;
const int N = 5e5+1000;
ll ans[N],anscnt,qcnt;
struct Q{
	ll t,ansid,val,p;//1.p < 2.p 
	bool operator < (const Q& r)const { return p==r.p?t<r.t:p<r.p;}
}qs[N3],tmp[N3];
void cdq(int L,int R){
	if(R-L<=1)return ;
	int M = (L+R)>>1;
	cdq(L,M),cdq(M,R);
	//merge
	int l=L,r=M,o=0;
	ll sum=0;
	while(l<M&&r<R){
		if(qs[l]<qs[r]){
			if(qs[l].t==1)sum+=qs[l].val;
			tmp[o++]=qs[l++];
		}
		else {
			if(qs[r].t==2)ans[qs[r].ansid]-=sum;
			else if(qs[r].t==3)ans[qs[r].ansid]+=sum;
			tmp[o++]=qs[r++];
		}
	}
	while(l<M)tmp[o++]=qs[l++];
	while(r<R){
			if(qs[r].t==2)ans[qs[r].ansid]-=sum;
			else if(qs[r].t==3)ans[qs[r].ansid]+=sum;
			tmp[o++]=qs[r++];
	}
	for(int i=0;i<o;i++)qs[L+i]=tmp[i];
}
void inp(){
	ll n,m,a,b,c;scanf("%lld%lld",&n,&m);
	for(int i = 1;i<=n;i++)scanf("%lld",&a),
		qs[qcnt].t=1,qs[qcnt].val=a,qs[qcnt].p=i,qcnt++;
	for(int i=0;i<m;i++){scanf("%lld%lld%lld",&a,&b,&c);
		if(a==1){
			qs[qcnt].t=1,qs[qcnt].val=c,qs[qcnt].p=b,qcnt++;
		}
		else {
			qs[qcnt].t=2,qs[qcnt].ansid=anscnt,qs[qcnt].p=b-1,qcnt++,
				qs[qcnt].t=3,qs[qcnt].ansid=anscnt,qs[qcnt].p=c,qcnt++,anscnt++;
		}
	}
	cdq(0,qcnt);
	for(int i=0;i<anscnt;i++)printf("%lld\n",ans[i]);
}
//p3374_cdq.cc by xsthunder at Thu Sep  7 21:55:44 2017

