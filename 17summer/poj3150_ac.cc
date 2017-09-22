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
	freopen("poj3150.in","r",stdin);
#endif
	inp();
	return 0;
}
const int N = 600;
ll A[N];
ll B[N];
ll m,n;
void MtM(ll ans[N],ll a[N],ll b[N]){
	ll c[N];MS(c,0);
	for(int j=0;j<n;j++){
		for(int k=0;k<n;k++){
			c[j]+=a[k]*b[(j-k+n)%n];
			c[j]%=m;
		}
	}
	memcpy(ans,c,sizeof(c));
}
void qp(ll ans[N],ll k){
	ll b[N];MS(b,0);b[0]=1;
	while(k){
		if(k&1){
			MtM(b,b,ans);
		}
		MtM(ans,ans,ans);
		k>>=1;
	}
	memcpy(ans,b,sizeof(b));
}
void inp(){
	ll d,k;
	scanf("%lld%lld%lld%lld",&n,&m,&d,&k);
	MS(A,0);
	for(int i=0;i<n;i++)scanf("%lld",&B[i]);
	for(int i=-d;i<=d;i++){ A[(i+n)%n]=1; }
	qp(A,k);
	for(int i=0;i<n;i++){
		ll sum=0;
		if(i)putchar(' ');
		for(int j=0;j<n;j++){
			sum+=A[(j-i+n)%n]*B[j];
			sum%=m;
		}
		printf("%lld",sum);
	}
	putchar('\n');
}
//poj3150.cc by xsthunder at Mon Sep 18 16:52:20 2017

//AC at Tue Sep 19 08:42:22 2017
 
