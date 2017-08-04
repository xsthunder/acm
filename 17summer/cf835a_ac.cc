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
void inp(){
	int s,v1,v2,t1,t2;scanf("%d%d%d%d%d",&s,&v1,&v2,&t1,&t2);
	int ans = s*(v1-v2)+2*(t1-t2);
	if (ans<0)printf("%s","First");
	else if(ans==0)printf("%s","Friendship");
	else printf("%s","Second");
	printf("\n");
}
//cf835a.cc by xsthunder at Thu Aug  3 08:25:09 2017

//AC at Thu Aug  3 08:34:59 2017
 
