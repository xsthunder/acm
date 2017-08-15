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
	freopen("at80d.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
int h,w;
const int H = 2000,W=2000;
int g[H][W];
int A[20000];
int B[20000];
const int D[4][2]={
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
const int X =0,Y=1;
void inp(){
	scanf("%d%d",&h,&w);
	int n;scanf("%d",&n);
	int i;for(i=1;i<=n;i++)scanf("%d",&A[i]);
	MS(g,-1);
	int j;for(i=1;i<=h;i++)for(j=1;j<=w;j++)g[i][j]=0;
	int x;
	int cnt=0;
	int k;
	for(k=1;k<=n;k++){
		for(i=0;i<A[k];i++){
			B[cnt]=k;
			cnt++;
		}
	}
	x=1;int y=1;int d=0;
	for(i=0;i<cnt;i++){
		g[x][y]=B[i];
		while(g[x+D[d][X]][y+D[d][Y]]){
			if(i==cnt-1)break;
			d++;d%=4;
		}
		x+=D[d][X],y+=D[d][Y];
	}
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
			if(j!=1)printf(" ");
			printf("%d",g[i][j]);
		}
		printf("\n");
	}
}
//at80d.cc by xsthunder at Sun Aug  6 21:03:37 2017

//AC at Thu Aug 10 09:05:32 2017
 
