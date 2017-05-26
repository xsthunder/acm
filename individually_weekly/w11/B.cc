#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
const int N = 30;
int m[30][30];
int u[300];
int ma=0;
int dirs[4][2]={
	{-1,0},
	{0,-1},
	{1,0},
	{0,1}
};
void sea(int x,int y,int cnt ){
	iF cout<<x<<' '<<y<<' '<<(char)m[x][y]<<' '<<u[m[x][y]]<<' '<<cnt<<endl;
	if(u[m[x][y]])return ;
	u[m[x][y]]=1;
	int dx,dy;
	ma=max(ma,cnt);
	iF cout<<'c'<<' '<<x<<' '<<y<<' '<<m[x][y]<<' '<<u[m[x][y]]<<' '<<cnt<<endl;
	for(int c=0;c<4;c++){
		dx=dirs[c][0];
		dy=dirs[c][1];
		sea(x+dx,y+dy,cnt+1);
	}
	u[m[x][y]]=0;
}
void inp(){
	ma=0 ;
	memset(m,0,sizeof(m));
	for(int i=0;i<N;i++){
		m[0][i]='0';
		m[i][0]='0';
	}
	u['0']=1;

	int r ,s ;
	cin>>r>>s;
	for(int i = 0;i<r;i++){
		for(int j = 0; j < s ;j++){
			cin>>m[i+1][j+1];
		}
	}
	pM(m,10,10,3);
	sea(1,1,1);
	cout<<ma<<endl;
}
//B.cc by xsthunder at Thu May  4 18:07:16 2017

