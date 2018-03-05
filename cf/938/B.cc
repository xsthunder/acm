#include<cstdio>
#include<algorithm>
#include<cmath>
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
const int A = 1, B = 1e6;
void inp(){
	int n,tmp;
	scanf("%d",&n);
	int ans = 0;
	while( n-- ){
		scanf("%d", &tmp);
		ans = max( ans, min( abs(tmp - A), abs( tmp - B)));
	}
	printf("%d\n",ans);
}
//B.cc by xsthunder at Fri Feb 16 23:34:09 2018

