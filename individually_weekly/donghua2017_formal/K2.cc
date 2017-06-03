#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
const int R =0;
const int C =1;
const int D =4;
int dir[4][2]={
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
const int N = 200;
int n,m;
int vis[N][N];
int a[N][N];
void ds(int r,int c,int d){
	cin>>a[r][c];
	vis[r][c]=1;
	for(int i =0;i<D;i++){
		int nr=r+dir[d][R];
		int nc=c+dir[d][C];
		if(!vis[nr][nc]){
			ds(nr,nc,d);
			return ;
		}
		else {
			d++;
			d%=D;
		}
	}
}
void inp(){
	if(!(cin>>n>>m))exit(0);
	MS(vis);
	for(int i =0;i<n+2;i++){
		 vis[0][i]=1;
		 vis[i][0]=1;
		 vis[n+1][i]=1;
		 vis[i][n+1]=1;
	}
	ds(1,1,0);
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j!=1)cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
//K2.cc by xsthunder at Sat Jun  3 15:11:48 2017

