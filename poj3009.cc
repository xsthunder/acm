#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
typedef long long int ll;
using namespace std;
const int N=20+5;
int A[N][N];
int w,h;
const int test=0;
void show(){
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			printf("%2d", A[i][j]);
		}
		printf("\n");}
}
int mov[2][4]={
	-1,1,0,0,
	0,0,-1,1
};
int cnt;
void solve(int i,int wc,int hc){
	if(test)show();
	if(test)cout<<"root"<<i<<' ' <<hc<< ' '<<wc<<endl;
	if(i==11){
		return;
	}
	int x,y;
	for(int c=0;c<4;c++){
		x=wc+mov[0][c];
		y=hc+mov[1][c];
		if(x<1||x>w||y<1||y>h)continue;
		if(A[y][x]==1)continue;
		if(test)cout<<'c'<<' '<<i<<' ' <<y<< ' '<<x<<endl;
		if(test)cout<<'A'<<' '<<A[y][x]<<endl;
		while(A[y][x]==0){
			x=x+mov[0][c];
			y=y+mov[1][c];
			if(x<1||x>w||y<1||y>h)break;
		}
		if(test)cout<<"moving "<<i<<' ' <<y<< ' '<<x<<endl;
		if(x<1||x>w||y<1||y>h)continue;
		if(A[y][x]==3){
			if(test)cout<<"min"<<' '<<i<<' '<<cnt<<endl;
			cnt=min(i,cnt);
		}
		else if(A[y][x]==1){
			A[y][x]=0;
			solve(i+1,x-mov[0][c],y-mov[1][c]);
			A[y][x]=1;
		}
	}
	if(test)show();
	if(test)cout<<"root"<<i<<' ' <<hc<< ' '<<wc<<endl;
}
int main()
{
	while(scanf("%d%d", &w,&h)!=EOF&&w&&h){
		memset(A,-1,sizeof(A));
		int x;
		int ws,hs;
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				scanf("%d", &x);
				switch(x){
					case 2:
						hs=i;ws=j;x=0;break;
				}
				A[i][j]=x;
			}
		}
		cnt=20;
		solve(1,ws,hs);
		printf("%d\n", cnt==20?-1:cnt);
	}
	return 0;
}
//poj3009.cc
//generated automatically at Fri Sep  9 10:41:33 2016
//by xsthunder

