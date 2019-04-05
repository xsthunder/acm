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
	int a,b;scanf("%d%d",&a,&b);
	int c = b - a;
	printf("%d", ( c + 1 ) * c / 2 - b);
}
//b.cc by xsthunder at Fri Jul 27 23:12:40 2018

