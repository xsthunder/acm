#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;  typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
const int N  =200;
int G[N][N],R[N][N],P[N][N],X[N][N];
int cnt;
void BK2(int d,int r,int p,int x){
	if(cnt>1000)return;
	if(p==0&&x==0){
		//find one, content vertex on R[d][1~r]
		cnt++;
		return;
	}
	int key=P[d][1];
	for(int j=1;j<=p;j++){
		int i=0,nr=0,np=0,nx=0,v=P[d][j];
		if(G[key][v])continue;
		for(i=1;i<=r;i++)R[d+1][++nr]=R[d][i];R[d+1][++nr]=v;
		for(i=1;i<=p;i++)if(G[v][P[d][i]])P[d+1][++np]=P[d][i];
		for(i=1;i<=x;i++)if(G[v][X[d][i]])X[d+1][++nx]=X[d][i];
		BK2(d+1,nr,np,nx);
		P[d][j]=0;X[d][++x]=v;
	}
}
void inp(){
	cnt=0;
	int n,m;if(scanf("%d%d",&n,&m)==EOF)exit(0);
	MS(G,0),MS(R,0),MS(P,0),MS(X,0);
	int i,a,b;
	for(i=1;i<=m;i++)scanf("%d%d",&a,&b),G[a][b]=G[b][a]=1;
	for(i=1;i<=n;i++)P[0][i]=i;
	BK2(0,0,n,0);
	if(cnt>1000)puts("Too many maximal sets of friends.");
	else printf("%d\n",cnt);
}
//poj2989.cc by xsthunder at Tue Aug 15 10:07:52 2017

//AC at Tue Aug 15 10:35:45 2017
 
