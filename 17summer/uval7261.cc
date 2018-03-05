#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const ll N = 1e6 + 10;
ll sta[N];
void inp(){
	ll R;scanf("%lld",&R);
	ll n;scanf("%lld",&n);
	ll l,t,w,h,a,b;MS(sta,0);
	for(int i =0 ;i<n;i++){
		scanf("%lld%lld%lld%lld",&l,&t,&w,&h);
		a = l + 1, b= l + w + 1;
		sta[a]+=h,sta[b]-=h;
	}
	for(int i =1;i<=R;i++){ sta[i]+=sta[i-1]; }
	for(int i =1;i<=R;i++){ sta[i]+=sta[i-1]; }
//	for(int i =0;i<=10;i++){
//		printf("%d %d\n",i,sta[i]);
//	}
	ll tol = sta[R];
	//printf("tol %lld\n",tol);
	ll r = R;
	for(;r>0&&(sta[r-1] >= tol - sta[r-1]);)r--;
	for(;r<R&&(sta[r+1] == sta[r]);)r++;
	printf("%lld\n", r);
}
//uval7261.cc by xsthunder at Thu Nov  2 08:57:29 2017

