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
void inp(){
	ll n,m,k;scanf("%lld%lld",&n,&m);
	k = n - m;
	ll cost = m * 1900 + k * 100;
	for(int i = 0;i<m;i++){
		cost *=2;
	}
	printf("%lld\n",cost);
}
//C.cc by xsthunder at Sat Nov 11 20:40:25 2017

//AC at Sat Nov 11 20:57:28 2017
 
