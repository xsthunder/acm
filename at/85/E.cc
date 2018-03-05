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
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 100+10;
ll a[N];
int c[N];
void inp(){
	int n;scanf("%d",&n);
	for(int i =1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i = n;i>=1;i--){
		ll del = 0;
		for(int j = i;j<=n;j+=i){
			if(!c[i])del += a[j];
		}
		if(del < 0){ 
			for(int j = i;j<=n;j+=i)c[j] = 1; 
		}
	}
	ll ans = 0;
	for(int i =1;i<=n;i++){
		if(!c[i])ans += a[i];
	}
	printf("%lld\n",ans);
}
//E.cc by xsthunder at Sat Nov 11 20:57:36 2017

