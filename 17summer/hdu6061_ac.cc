#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N  =500000 ;
const int p = 998244353;
const int g = 3;
ll qp(ll x,ll e){
	ll b = 1;
	while(e){
		if(e&1)b*=x;
		e>>=1;
		x*=x;
		x%=p,b%=p;
	}
	return b;
}
template<typename T>
void change(T y[],int len){
	int i,j,k;
	for( i = 1,j = len/2;i<len-1;i++){
		if(i < j)swap(y[i],y[j]);
		k = len/2;
		while(j>=k){
			j -=k;
			k /=2;
		}
		if(j<k)j+=k;//is j   // less this condition ntt
	}
}
void ntt(ll y[], int len,int on){
	int h,j,k,i;
	change(y,len);
	for(h=2;h<=len;h<<=1){
		ll wh = qp(g,(p-1)/h);
		if(on<0)wh=qp(wh,p-2);
		for(j = 0;j<len;j+=h){
			ll w= 1;
			for(k = j;k<j+h/2;k++){
				ll u = y[k];
				ll t = w*y[k+h/2]%p;//chengfa mo p ntt spec
				y[k] = u+t;if(y[k]>=p)y[k]-=p;
				y[k+h/2] = u-t;if(y[k+h/2]<0)y[k+h/2]+=p;
				w = w*wh%p;// chengfa mo p , ntt spec
			}
		}
	}
	if(on == -1)for(i = 0;i<len;i++){
		ll I = qp(len,p-2);
		y[i]=y[i]*I%p;
	}
}
typedef long long ll;
const ll mod = 998244353;
ll fac[N+1];
ll ifac[N+1];
void init(){
	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=N;i++){
		fac[i]=fac[i-1]*i;fac[i]%=mod;
		ifac[i]=ifac[i-1]*qp(i,p-2);ifac[i]%=mod;
	}
}
ll C[N]; ll A[N*4]; ll B[N*4];
ll sum;
int n;
#define MS(x) memset(x,0,sizeof(x))
void pre(){
	MS(A),MS(B);sum=p-sum;
	for(int i=0;i<=n;i++){
		A[i]=qp(sum,i)*ifac[i];
		B[i]=C[n-i]*fac[n-i];
		A[i]%=mod;B[i]%=mod;
	}
}
int main(){
#ifdef XS
	freopen("hdu6061.in","r",stdin);
#endif
	int len1,len,i,x,m;
	init();
	while(scanf("%d",&len1)!=EOF){
		sum = 0;n=len1;
		for(i = 0;i<=len1;i++){ scanf("%d",&x);C[i]=x; }
		scanf("%d",&m);
		for( i = 0;i<m;i++){ scanf("%d",&x);sum+=x; } sum%=mod;
		len1++;
		len = 1;while(len<len1*2)len<<=1;
		pre();
		ntt(A,len,1);
		ntt(B,len,1);
		for(i = 0;i<=len;i++){A[i]*=B[i],A[i]%=mod;}
		ntt(A,len,-1);
		for(i = 0;i<=n;i++){
			printf("%lld ",A[n-i]*ifac[i]%mod);
		}
		printf("\n");
	}
	return 0;
}

//AC at Tue Aug  8 21:57:28 2017
 
