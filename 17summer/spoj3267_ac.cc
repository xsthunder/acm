#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; ; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("spoj3267.in","r",stdin);
#endif
	//while(1)
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}

const int QQ = 200000 +100,N = 300000,NN=1000000;
struct P{
	int first,second,i;
};
P Q[QQ];
int ans[QQ];
int A[N];
int T[N];
int R[NN];
int n;
#define lb(x) ((x)&(-x))
void ad(int p,int v){
	while(p<=n){
		T[p]+=v;
		p+=lb(p);
	}
}
int sum(int p){
	int ans=0;
	while(p>0){
		ans+=T[p];
		p-=lb(p);
	}
	return ans;
}
void inp(){
	int i;
	scanf("%d",&n);for(i = 1;i<=n;i++)scanf("%d",&A[i]);
	int q;for(scanf("%d",&q),i=1;i<=q;i++)Q[i].i=i,scanf("%d%d",&Q[i].second,&Q[i].first);
	sort(Q+1,Q+1+q,[](P &a,P b){return a.first<b.first;});
	MS(T,0);MS(R,-1);
	int a,b,cur = 1;
	for(i = 1;i<=q;i++){
		a=Q[i].second,b=Q[i].first;
		for(;cur<=b;cur++){
			if(R[A[cur]]==-1)ad(cur,1),R[A[cur]]=cur;
			else ad(R[A[cur]],-1),ad(cur,1),R[A[cur]]=cur;
		}
		a = sum(a-1),b=sum(b);
		ans[Q[i].i]=b-a;
	}
	for(i =1;i<=q;i++)printf("%d\n",ans[i]);
}
//spoj3267.cc by xsthunder at Fri Aug  4 20:30:32 2017

//AC at Fri Aug  4 21:33:50 2017
 
