#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;  typedef long long ll;
void inp();
const int P = 8e4;
const int mod = 998244353,N=1e6+10,R=1e6;
int p[P],pcnt=0;
int isp[R];
void getp(int x){
	MS(isp,-1);
	int j=0,i;
	for(i=2;i<=x;i++){
		if(isp[i]){
			p[pcnt]=i,pcnt++;
			for(j=i+i;j<x;j+=i)isp[j]=0;
		}
	}
}
int main(){
#ifdef XS
	freopen("hdu6069.in","r",stdin);
#endif
	getp(R);
	int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
ll pre[N],sum[N];
void inp(){
	ll l,r,k;
	int i;
	scanf("%lld%lld%lld",&l,&r,&k);
	for(i=0;i<r-l+1;i++){
		pre[i]=l+i,sum[i]=1;
	}
	ll L;
	int cnt;
	int b = sqrt(r);
	for(i=0;i<pcnt&&p[i]<=b;i++){
		for(L = ((l+p[i]-1)/p[i])*p[i];L<=r;L += p[i]){
			cnt=0;
			while(pre[L-l]%p[i]==0&&pre[L-l]>1){
				pre[L-l]/=p[i];
				cnt++;
			}
			sum[L-l]*=k*cnt+1;
			sum[L-l]%=mod;
		}
	}
	ll ans=0;
	for(i=0;i<r-l+1;i++){
		if(pre[i]>1){
			sum[i]*=k*1+1;
			sum[i]%=mod;
		}
		ans+=sum[i];
		ans%=mod;
	}
	printf("%lld\n",ans);
}
//hdu6069.cc by xsthunder at Sat Aug  5 21:31:49 2017

//AC at Sat Aug  5 22:09:22 2017
 
