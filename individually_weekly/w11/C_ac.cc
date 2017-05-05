#include<iostream>
#include<queue>
#include<utility>
#include<cstring>
#include<iomanip>
using namespace std;
typedef pair<int ,int > P;
#define iF if(Te)
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
void inp(int,int );
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r,c;
	while(cin>>r>>c){
		if(!r&&!c)return 0;
		inp(r,c);
	}
	return 0;
}
int m[200][200];
int vis[200][200];
char  s [300];
#define cor(r,s) m[r][s]
int dir[8][2]={
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1},
	{-1,-1}
};
int bfs(int r,int c ){
	if(vis[r][c])return 0;
	vis[r][c]=1;
	if(!cor(r,c))return 0;
	int cnt=0;
	cnt++;
	queue<P> q;
	q.push(P(r,c));
	while(!q.empty()){
		r=q.front().first;
		c=q.front().second;
		q.pop();
		if(cor(r,c))
			for(int i=0;i<8;i++){
				int x = r+dir[i][0];
				int y = c+dir[i][1];
				cnt+=bfs(x,y);
			}
	}
	return cnt;
}
void inp(int r,int c){
	memset(m,0,sizeof(m));
	memset(vis,0,sizeof(vis));
	for(int i =0;i< r;i++){
		cin>>s;
		for(int j=0;j<c;j++){
			cor(i+1,j+1)=s[j]=='*'?0:1;
		}
	}
	int cnt=0;
	for(int i =0;i<r;i++){
		for(int j =0;j<c;j++){
			cnt+=(bfs(i+1,j+1)?1:0);
		}
	}
	cout<<cnt<<endl;
}
//C.cc by xsthunder at Fri May  5 17:43:23 2017

//AC at Fri May  5 18:33:52 2017
 
