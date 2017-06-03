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
const int N = 200;
typedef long long ll;
ll a[N][N];
const int D = 4;
const int R = 0;
const int C = 1;
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
void inp(){
	int n,m;
	if(!(cin>>n>>m))exit(0);
	memset(a,0,sizeof(a));
	int r,c;
	for(int i=1;i<=n;i++){
		for(int j =1;j<=m;j++){
			a[i][j]=-1;
		}
	}
	r=1,c=1;
	int d=0;
	int nr,nc;
	int cnt =0;
	for(int i=1;i<=n;i++){
		for(int j =1;j<=m;j++){
			//cin>>a[r][c];
			a[r][c]=++cnt;
			nr =r+dir[d][R],nc=c+dir[d][C];
			if(a[nr][nc]!=-1){
				d+=1;
				d%=4;
				r=r+dir[d][R],c=c+dir[d][C];
			}
			else {
				r=nr;
				c=nc;
			}
		}
	}
	for(int i =1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(j!=1)cout<<' ';
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
//K.cc by xsthunder at Sat Jun  3 14:25:18 2017

