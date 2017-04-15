const bool TEST=0;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
#include<sstream>
#include<stack>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
const int N  = 250;
int G[N][N];
int used[N][N];
Point dir[4];
void sol(){
	int n , m ;
	dir[0]=MK(1,0);
	dir[1]=MK(0,1);
	dir[2]=MK(-1,0);
	dir[3]=MK(0,-1);
	cin>>m>>n;
	for(int i =0 ; i < m;i++){
		for(int j =0 ; j < n;j++){
			scanf("%d", &G[i][j]);
			used[i][j]=1;
		}
	}
	int x = 0 ,y = 0 ;
	int d = 0 ;
	printf("%d",G[x][y]);
	used[x][y]=0;
	while(1){
		Point p;
		int nxtx,nxty;
		p = dir[d];
		nxtx=x+p.first,nxty=y+p.second;
		if(!used[nxtx][nxty]){
			d=(d+1)%4;
			p = dir[d];
			nxtx=x+p.first,nxty=y+p.second;
			if(!used[nxtx][nxty])return ;
		}
		x=nxtx,y=nxty;
		IF cout<<x<<y;
		printf(" %d",G[x][y]);
		used[x][y]=0;
	}
}
int main()
{
	sol();
	return 0;
}
//66.cc
//generated automatically at Sat Feb  4 16:25:22 2017
//by xsthunder

