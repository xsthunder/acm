#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<cassert>
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
char A[N][N];
char V[N][N];
int w,h;
int W,H;
char s[N];
char color(char x){
	if(x=='.')return 1;
	if(x=='#')return 0;
	else assert(0);
}
void solve(){
	int mov[2][4]={
		-1,0,1,0,
		0,1,0,-1,
	};
	int cnt=0;
	queue<pair<int,int> >q;
	q.push(make_pair(H,W));
	A[H][W]=0;
	pair<int, int > p;
	while(q.size()){
		p=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<4;i++){
			int r=mov[0][i]+p.first;
			int c=mov[1][i]+p.second;
			if(A[r][c]){
				q.push(make_pair(r,c));
				A[r][c]=0;
			}
		}
	}
	printf("%d\n",cnt);
}
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	
	while(scanf("%d%d", &w,&h)&&w&&h){
//		cout<<w<<' '<<h<<endl;
		memset(V,0,sizeof(V));
		memset(A,0,sizeof(A));
		for(int i=1;i<=h;i++){
			scanf("%s", s);
			for(int j=1;j<=w;j++){
				if(s[j-1]=='@'){
					H=i;
					W=j;
				}
				else A[i][j]=color(s[j-1]);
			}
		}
		solve();
		bool test=0;
		if(test){
			cout<<W<<' '<<H<<endl;
		for(int i=0;i<=h;i++){
			for(int j=0;j<=w;j++){
				printf("%d",A[i][j]);
			}
			printf("\n");
		}
		for(int i=0;i<=h;i++){
			for(int j=0;j<=w;j++){
				printf("%d",V[i][j]);
			}
			printf("\n");
		}
		}
	}
	//insert code above
	return 0;
}
//poj1979.cc
//generated automatically at Wed Sep  7 18:58:58 2016
//by xsthunder


//AC

