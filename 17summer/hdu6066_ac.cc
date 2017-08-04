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
	int t,x,ans=0;scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		ans+=x<=35;
	}
	printf("%d\n",ans);
	return 0;
}
//hdu6066.cc by xsthunder at Wed Aug  2 10:13:05 2017

//AC at Wed Aug  2 10:15:31 2017
 
