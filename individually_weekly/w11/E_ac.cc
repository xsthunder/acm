#include<iostream>
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
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
char s [300];
int m[300][300];
int vis[300][300];
#define cor(a,b) m[a][b]
#define vi(a,b) vis[a][b]
int dir[4][2]={
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
int dfs(int r,int c){
	if(!cor(r,c))return 0;
	if(vi(r,c))return 0;
	int cnt = 0;
	cnt++;
	vi(r,c)=1;
	for(int i=0;i< 4;i++){
		int x= r+dir[i][0];
		int y= c+dir[i][1];
		cnt+=dfs(x,y);
	}
	return cnt;
}
void inp(){
	while(1){
		MS(m);
		MS(vis);
		int r,c;
		cin>>c>>r;
		if(!r||!c)return ;
		int si,sj;
		for(int i=0;i<r;i++){
			cin>>s;
			for(int j=0;j<c;j++){
				int val = -1;
				switch(s[j]){
					case '@':
						si=i+1;
						sj=j+1;
					case '.':
						val = 1;
						break;
					case '#':
						val = 0;
						break;
				}
				cor(i+1,j+1)=val;
			}
		}
		//pM(m,r+2,c+2,1);

		cout<<dfs(si,sj)<<endl;
	}

}
//E.cc by xsthunder at Fri May  5 23:50:35 2017

//AC at Sat May  6 00:04:59 2017
 
