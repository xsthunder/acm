#include<cstdio>
#include<cassert>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef long long ll;
typedef unsigned U; typedef pair<ll,ll> P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
int TT=0;
const int N= 4e4;
ll A[N];
ll n,m;
ll gcd(ll a,ll b){ return a==0?b:gcd(b%a,a); }
void inp(){
	scanf("%lld%lld",&n,&m);if(!n&&!m)exit(0);
	for(int i=0;i<n;i++)scanf("%lld",&A[i]);
	sort(A,A+n);
	P ans(0,0);ans.second=n*n;
	ll *it;
	for(ll b,tar,i =0;i<n;i++){
		b=A[i];
		if(b<0){
			tar=m/b;
			if(tar>0)if(m%b){ tar++; }
			it=lower_bound(A,A+n,tar);
			ans.first+=it-A;
		}
		else if(b==0){ if(m<0)ans.first+=n; }
		else {
			tar=m/b;
			if(tar<0)if(m%b){tar--;}
			it=upper_bound(A,A+n,tar);
			ans.first+=A+n-it;
		}
#ifdef XS
	printf("b:%lld tar:%lld %lld %lld\n",b,tar,ans.first,ans.second);
#endif
	}
	assert(ans.second>0);
	assert(ans.first>=0);
	if(ans.first>0){
		ll g= gcd(ans.first,ans.second);
		ans.first/=g,ans.second/=g;
	}
	printf("Case %d: %lld/%lld\n",++TT,ans.first,ans.second);
}
//la4269.cc by xsthunder at Wed ansug 30 09:33:40 2017

//AC at Wed Aug 30 10:04:47 2017
 
