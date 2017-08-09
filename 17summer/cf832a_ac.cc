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
	//while(1)
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
char ans[][10]={
	"NO","YES"
};
void inp(){
	ll n,k;
	scanf("%lld%lld",&n,&k);
	n/=k;
	printf("%s\n",ans[n&1]);
}
//cf832a.cc by xsthunder at Sat Aug  5 08:22:49 2017

//AC at Sat Aug  5 08:33:26 2017
 
