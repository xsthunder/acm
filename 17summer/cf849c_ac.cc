#include<cstdio>
#include<cstdlib>
#include<cassert>
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
const int  N = 500;
int fa[N];
P a[N];
void inp(){
	fa[0]=fa[1]=0;
	for(int i=2;i<N;i++){
		fa[i]=fa[i-1]+i-1;
#ifdef XS
		printf("%d %d\n",i,fa[i]);
#endif
	}
	int k;scanf("%d",&k);int d,r;
	if(!k){
		puts("a");
		return;
	}
	int cnt=0;
	for(int i=N-1;k&&i>=2;i--){
		r=k%fa[i],d=k/fa[i];
		if(d)a[cnt]=P(d,i),cnt++;
		k=r;
	}
	char ccnt='a';
	for(int i=0;i<cnt;i++){
		for(int j=0;j<a[i].first;j++){
			for(int z=0;z<a[i].second;z++){
				putchar(ccnt);
			}
			ccnt++;
		}
	}
	assert(ccnt<='z');
	assert(k==0);
	putchar('\n');
}
//cf849c.cc by xsthunder at Mon Sep  4 16:08:56 2017

//AC at Tue Sep  5 09:23:10 2017
 
