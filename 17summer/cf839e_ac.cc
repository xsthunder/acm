#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;; typedef long long ll;
const int N  =100;
int G[N][N],R[N][N],P[N][N],X[N][N];
int ma=1;
void BK2(int d,int r,int p,int x){
	if(p==0&&x==0){
		if(r>ma){
			ma=r;
		}
		//find one, content vertex on R[d][1~r]
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
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
void inp(){
	int n,k;scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){ scanf("%d",&G[i][j]); }
	}
	for(int i =1;i<=n;i++)P[0][i]=i;
	BK2(0,0,n,0);
//	printf("%d\n",ma);
	if(ma==1)puts("0");
	else printf("%.9f\n",double(k*k*(ma-1))/2/ma);
}
//cf839e.cc by xsthunder at Tue Aug 22 09:55:20 2017

//AC at Tue Aug 22 10:10:26 2017
 
