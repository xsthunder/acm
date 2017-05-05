#include<iostream>
#include<sstream>
#include<string>
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

typedef unsigned U;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
int used[300];
int m[30][30];
int mcnt =0;
#define cc(r,s) used[m[r][s]]

int dir[4][2]={
	{-1,0},
	{0,1},
	{1,0},
	{0,-1}
};
void dfs(int r,int s,int cnt){
	if(cc(r,s)){
		return ;
	}
	cc(r,s)=1;
	if(mcnt<cnt)mcnt=cnt;
	for(int c =0;c<4;c++){
		int x =r+dir[c][0];
		int y =s+dir[c][1];
		dfs(x,y,cnt+1);
	}
	cc(r,s)=0;
}
void inp(){
	int r,s;
	cin>>r>>s;
	memset(m,0,sizeof(m));
	memset(used,0,sizeof(used));
	//cout<<r<<s<<endl;
	char str[30];
	for(int i=0;i< r;i++){
		cin>>str;
		for(int j=0;j< s;j++){
			m[i+1][j+1]=str[j];
		}
	}
	used[0]=1;
	dfs(1,1,1);
	cout<<mcnt<<endl;
}
//B.cc by xsthunder at Fri May  5 16:23:09 2017

//AC at Fri May  5 17:18:23 2017
 
