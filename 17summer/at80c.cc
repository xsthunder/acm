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
	inp();
	return 0;
}
int cnt2,cnt4;
void inp(){
	int f,i,x;
	int n;scanf("%d",&n);
	for(i=0;i<n;i++){scanf("%d",&x);
		if(x%4==0)cnt4++;
		else if(x%2==0)cnt2++;
	}
	if(cnt2)n-=cnt2,n++;
	if(cnt4>=n/2)f=1;
	else f=0;
	char ans[][10]={"NO","YES"};
	puts(ans[f]);
}
//at80c.cc by xsthunder at Sun Aug  6 20:08:31 2017

