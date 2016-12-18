const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
ll lcm(ll a,ll b){
	return a/__gcd(a,b)*b;
}
const int N=1e6;

void sol(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		ll ans=0;
		ll s[3];
		ll p[3];
		ll b;
		scanf("%lld",&b);
		for(int c=0;c<=1;c++){
			scanf("%lld%lld", &p[c],&s[c]);
		}
		for(int c=0;c<=1;c++){
			ll res=b%p[c];
			ll tmpans=b/p[c]*s[c];
			tmpans+=res/p[!c]*s[!c];
			ans=max(tmpans,ans);
//			cout<<ans<<endl;
		}
		for(int c=0;c<=1;c++){
			ll res=b%p[c];
			ll tmpans;
			if(b/p[c]>=1){
				tmpans=(b/p[c]-1)*s[c];
				res+=p[c];
			}
			tmpans+=res/p[!c]*s[!c];
			ans=max(tmpans,ans);
//			cout<<ans<<endl;
		}
		printf("Case #%d: ", t);
		cout<<ans<<endl;
	}
//		ll lcmnum=lcm(p[1],p[2]);
//		int pre=b/lcmnum;
//		if(b>p[1]&&b>p[2]){
//			cout<<0<<endl;
//		}
//		if(b<=lcmnum){
//			b=b%lcmnum;
//			if(s[1]*p[2]>s[2]*p[1]){
//				ans+=p[1]*pre;
//			}
//			else ans+=p[2]*pre;
//		}
//		for(int i=1;i<=b;i++){
//			for(int c=1;c<=2;c++)
//				if(i>=p[c]){
//					dp[i]=max(dp[i],dp[i-p[c]]+s[c]);
//			}
//		}
//		printf("Case #%d: ", t);
//		cout<<ans+dp[b]<<endl;
//	}
}
int main()
{
	sol();
	return 0;
}
//A.cc
//generated automatically at Sun Dec 11 19:12:22 2016
//by xsthunder

