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
	//freopen(".in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
namespace RMQ_BIT{
	const int N = 100000+1000;
	int n;
#define lb(z) ((z)&(-z))
	ll c1[N],c2[N],num[N];
	void init(){MS(c1,0),MS(c2,0),MS(num,0);}
	ll sum(ll * r,int i){
		ll ans=0;
		for(;i>0;i-=lb(i)){ ans+= r[i]; }
		return ans;
	}
	void add(ll *r,int i,ll v){
		for(;i<=n;i+=lb(i)){ r[i]+=v; }
	}
}
using namespace RMQ_BIT;
void inp(){
	int a,b,c;scanf("%d",&n);if(!n)exit(0);
	init();
	c=1;
	for(int i=1;i<=n;i++){scanf("%d%d",&a,&b);
		add(c1,a,c),add(c1,b+1,-c);
		add(c2,a,c*(a-1)),add(c2,b+1,-(c*(b+1-1)));
	}
	for(int i=1;i<=n;i++){
		a=b=i;
		ll ans=(a-1)*sum(c1,a-1)-sum(c2,a-1);
		ans=b*sum(c1,b)-sum(c2,b)-ans;
		if(i!=1)putchar(' ');printf("%lld",ans);
	}
	putchar('\n');
}
//RMQ_BIT.cc by xsthunder at Wed Sep  6 21:14:31 2017
//ac HDU1556
//AC at Wed Sep  6 22:05:03 2017
 
