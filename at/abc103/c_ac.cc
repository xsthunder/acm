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
	int n;scanf("%d",&n);
	int a;
	ll sum = 0;
	for(int i =0;i<n;i++){
		scanf("%d",&a);
		sum += a;
	}
	printf("%lld", sum - n);
}
//c.cc by xsthunder at Wed Jul 25 22:55:02 2018

//AC at Wed Jul 25 23:18:24 2018
 
