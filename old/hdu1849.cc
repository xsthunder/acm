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
const int M=1000;
int SG[M+10];
int m;
int K[M+10];
void solve(){
	SG[0]=0;
	for(int i=1;i<=1000;i++){
		set<int >s ;
		for(int j=0;j<i;j++){
			s.insert(SG[j]);
		}
		int g=0;
		while(s.count(g)!=0)g++;
		SG[i]=g;
	}
}
void cal(){
	int x=0;
	for(int i=0;i<m;i++){
		x^=SG[K[i]];
	}
	puts(x!=0?"Rabbit Win!":"Grass Win!");
}
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	solve();
	while(scanf("%d", &m)!=EOF&&m){
		memset(K,0,sizeof(K));
		for(int i=0;i<m;i++){
			scanf("%d", &K[i]);
		}
		cal();
	}
	//insert code above
	return 0;
}
//hdu1849.cc
//generated automatically at Fri Sep  2 16:03:46 2016
//by xsthunder

//AC

