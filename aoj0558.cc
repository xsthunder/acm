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
#include<cassert>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
typedef long long int ll;
using namespace std;
const bool test=0;
int n,w,h;
int const N=1000+10;
char A[N][N];
char V[N][N];
char s[N];
int _h,_w;
int mov[2][4]={
	0,0,-1,1,
	-1,1,0,0
};
void show(){
	if(test){
		for(int i=1;i<=_h;i++){
			for(int j=1;j<=_w;j++){
				printf("%2d",A[i][j]);
			}
			printf("\n");
		}

	}
}
const int H=0,W=1;
struct point{
	int h;
	int w;
	int cnt;
	point(int h=1,int w=1,int cnt=inf):h(h),w(w),cnt(cnt){}
};
int cor(char x,int i,int j){
	switch(x){
		case 'S':
			h=i;
			w=j;
			return 0;
			break;
		case 'X':
			return -1;
		case '.':
			return 0;
		default:
			return x-'0';
	}
}
int search(int goal){
	memset(V,0,sizeof(V));
	int cnt=0;
	queue<point> q;
	q.push(point(h,w,cnt));
	point p;
	if(test){cout<<"root"<<cnt<<' '<<h<<' '<<w<<endl;
		show();
	}
	while(q.size()){
		p=q.front();
		q.pop();
		h=p.h;
		w=p.w;
		cnt=p.cnt;
		if(V[h][w]!=0)continue;
		if(A[h][w]==goal){
			return cnt;
		}
		if(test)cout<<"q.size "<<q.size()<<" cnt "<<cnt<<' '<<h<<' '<<w<<' '<<(int)V[h][w]<<" goal "<<goal<<endl;
		for(int c=0;c<4;c++){
			int tmph=h+mov[H][c];
			int tmpw=w+mov[W][c];
			if(!V[tmph][tmpw]&&A[h][w]!=-1)q.push(point(tmph,tmpw,cnt+1));
		}
		V[h][w]=1;
	}
	assert(q.size());
}
void solve(){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=search(i);
	}
	cout<<sum<<endl;
}
int main()
{
	scanf("%d%d%d", &h,&w,&n);
	_h=h;
	_w=w;
	memset(A,-1,sizeof(A));
	for(int i=1;i<=_h;i++){
		scanf("%s",s);
		for(int j=1;j<=_w;j++){
			A[i][j]=cor(s[j-1],i,j);
		}
	}
	show();
	solve();
	return 0;
}
////aoj0558.cc
////generated automatically at Fri Sep  9 18:27:24 2016
////by xsthunder
//
//AC

