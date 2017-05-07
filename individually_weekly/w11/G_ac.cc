#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int ,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
int map[300][300];
int vis[300][300];
int dp[300][300][300];
int dir[4][2]={
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
char s[30];
char ans[2][40]={
	"No\n",
	"Yes\n"
};
void dfs(int i,int j ,int d){
	if(dp[i][j][d])return ;
	if(vis[i][j]){
		cout<<ans[1];
		exit(0);
	}
	dp[i][j][d]=1;
	vis[i][j]=1;
	for(int c=0;c<4;c++){
		if(c==(d+2)%4)continue;
		int x= i+dir[c][0];
		int y = j+ dir[c][1];
		if(map[i][j]==map[x][y])
			dfs(x,y,c);
	}
	vis[i][j]=0;
}
void inp(){
	int r,c;
	cin>>r>>c;
	int cnt =300;
	for(int i =0;i<c+2;i++){
		map[0][i]=cnt++;
		map[r+1][i]=cnt++;
	}
	for(int i=0;i<r;i++){
		cin>>s;
		for(int j=0;j<c;j++){
			map[i+1][j+1]=s[j];
		}
		map[i+1][0]=cnt++;
		map[i+1][c+1]=cnt++;
	}
	//pM(map,r+2,c+2,4);
	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
			for(int k=0;k<4;k++){
				dfs(i,j,k);
			}
		}
	}
	cout<<ans[0];
}
//G.cc by xsthunder at Sat May  6 11:10:15 2017

//AC at Sat May  6 11:40:12 2017
 
