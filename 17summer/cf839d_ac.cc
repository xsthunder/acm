#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
const int N = 2e5+100;
const int A = 1e6+100;
int a[A];
int main(){
#ifdef XS
	freopen("cf839d.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
ll f[N];
const ll mod  =1e9+7;
int cnt[A];
ll ans[A];
void inp(){
	int n;scanf("%d",&n);
	int i,x;
	for(f[0]=i=1;i<N;i++)f[i]=f[i-1]*2%mod;
	for(i=0;i<n;i++){
		scanf("%d",&x);a[x]++;
	}
	for(i=1;i<A;i++){
		for(x=i;x<A;x+=i){
			cnt[i]+=a[x];
		}
	}
	for(i = A-1;i>=2;i--){
		ans[i]=cnt[i]*f[cnt[i]-1]%mod;;
		for(x=i+i;x<A;x+=i){
			ans[i]-=ans[x];
			if(ans[i]<0)ans[i]+=mod;
		}
	}
	ll fin=0;
	for(i=2;i<A;i++){
		fin+=i*ans[i];
		fin%=mod;
	}
	printf("%lld\n",fin);
}
//cf839d.cc by xsthunder at Mon Aug 14 15:16:23 2017

//AC at Mon Aug 14 15:29:12 2017
 
