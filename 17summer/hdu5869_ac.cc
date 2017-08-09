#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int gcd(int a,int b){return a?gcd(b%a,a):b;}
int main(){
#ifdef XS
	freopen("hdu5869.in","r",stdin);
#endif
	//printf("%d",gcd(13,130));
	while(1)inp();
	return 0;
}
const int N = 100000+100,A=1000000+10;
int T[N]; int rec[A]; int a[N]; 
int ans[N];
struct Qu{
	int l,r,i;
}Q[N];
typedef vector<P> VI;
VI dp[N];
#define lb(z) ((z)&(-z))
int sum(int p){
	int ans=0;
	while(p){
		ans+=T[p];
		p-=lb(p);
	}
	return ans;
}
int i,n,q;
void ad(int p, int v){
	while(p<=n){
		T[p]+=v;
		p+=lb(p);
	}
}
void inp(){
	MS(T,0),MS(rec,-1);if(scanf("%d%d",&n,&q)==EOF)exit(0);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=q;i++)scanf("%d%d",&Q[i].l,&Q[i].r),Q[i].i=i;
	for(i=1;i<=n;i++){dp[i].clear(),dp[i].reserve(20);}
	int g,x;
	for(i=1;i<=n;i++){
#define pb(z,x) push_back(P(z,x)) 
		dp[i].pb(a[i],i);
		g = a[i];
		for(P p:dp[i-1]){
			x=gcd(p.first,a[i]);
			if(g!=x)dp[i].pb(x,p.second);
			g=x;
		}
	}
	sort(Q+1,Q+1+q,[](Qu &a,Qu&b){return a.r<b.r;});
	int l,r,ind;
	int cur=0;
	for(i=1;i<=q;i++){
		l=Q[i].l,r=Q[i].r,ind=Q[i].i;
		for(;cur<=r;cur++){
			for(P p:dp[cur]){
				if(rec[p.first]!=-1)ad(rec[p.first],-1);
				rec[p.first]=p.second,ad(p.second,1);
			}
		}
		ans[ind]=sum(r)-sum(l-1);
	}
	for(i=1;i<=q;i++)printf("%d\n",ans[i]);
}
//hdu5869.cc by xsthunder at Sat Aug  5 20:21:52 2017

//AC at Sat Aug  5 21:20:43 2017
 
