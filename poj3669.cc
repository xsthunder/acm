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
#include<cassert>
const int inf=0x7fffffff;
const bool test=0;
typedef long long int ll;
using namespace std;
const int N_=300+5;
struct point{
	int i;
	int j;
	int cnt;
};
bool I=0,J=1;
int mov[2][4]={
	0,0,1,-1,
	1,-1,0,0
};
int A[N_][N_];
void init();
void solve();
void init(){
	for(int i=0;i<N_;i++){
		A[0][i]=1;
		A[i][0]=1;
	}
}
void solve(){

}

int main()
{
	init();
	int m;
	scanf("%d", &m);
	int i,j,t;
	while(m--){
		scanf("%d%d%d", &j,&i,&t);
		A[i][j]=t;
		for(int c=0;c<4;c++){
			int &tmp=A[i+mov[I][c]][j+mov[J][c]];
			if(tmp==0){
				tmp=t;
			}
			else tmp=min(tmp,t);
		}
	}
	solve();
	
	return 0;
}
//poj3669.cc
//generated automatically at Sun Sep 11 11:43:08 2016
//by xsthunder

