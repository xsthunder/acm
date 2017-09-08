#include<cstdio>
#include<queue>
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
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
int a[200];
void inp(){
	int n;scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		a[i]=x&1;
	}
	int flag=a[1]&a[n]&(n&1);
	puts(flag?"yes":"no");
}
//cf849a.cc by xsthunder at Mon Sep  4 14:58:03 2017

//AC at Mon Sep  4 15:43:06 2017
 
