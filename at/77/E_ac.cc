#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	const int Te=1;
	#include<De>
#else 
	const int Te=0;
#endif
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("E.in","r",stdin);
#endif
	try{
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 1e5+5;
int n,m;
int a[N];
int mod;
//ll cal(int x){
//	ll ans = 0;
//	for(int i=2;i<=n;i++){
//		ans+=min((a[i]-a[i-1]+mod)%mod,(a[i]-x+mod)%mod+1);
//	}
//	return ans;
//}
ll p[3*N];
void inp(){
	scanf("%d%d",&n,&m);
	mod=m;
	for(int i =1;i<=n;i++){
		scanf("%d",&a[i]);
	}
#ifdef XS
//	for(int i = 0;i<m;i++){
//		printf("%d ->fav:%lld\n",i,cal(i));
//	}
#endif
	MS(p);
	ll all = 0;
	for(int i = 2;i<=n;i++){
		int l = a[i-1];
		int r = a[i];
		if(r<l)r+=m;
		all += r - l;
		if(r-l==1);
		else {
			p[l+2]+=1;
			p[r+1]+=l-r;
			p[r+2]+=r-l-1;
		}
	}
	for(int i = 1;i<=2*m+5;i++)p[i]+=p[i-1];
	for(int i = 1;i<=2*m+5;i++)p[i]+=p[i-1];
	
	ll ans = -1;
	for(int i = 1;i<=m;i++)ans=max(ans,p[i]+p[i+m]);
	printf("%lld\n", all - ans);
}
//E.cc by xsthunder at Fri Jul 14 16:37:25 2017

//AC at Fri Jul 14 21:50:19 2017
 
