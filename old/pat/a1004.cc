const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
int leaflevel[105];
vector<int > vi[105];
int maxlevel=0;
void log(int node ,int level){
	printf("at node: %d, at level: %d\n",node,level);
}
void dfs(int node, int level){
	if(vi[node].empty()){
		leaflevel[level]++;
		maxlevel=level;
		//log(node,level);
		return;
	}
	for(int x:vi[node]){
		dfs(x,level+1);
	}
}
void sol(){
	int n,m;
	scanf("%d%d",&n,&m);
	int leaves=n-m;
	while(m--){
		int id, k, x;
		scanf("%d%d",&id,&k);
		while(k--){
			scanf("%d",&x);
			vi[id].push_back(x);
		}
	}
	dfs(1,0);
	int a=leaflevel[0];
	//pA(leaflevel,5);
	printf("%d", a);
	for(int i=1;a<leaves;i++){
		printf(" %d",a );
		a+=leaflevel[i];
	}
}
int main()
{
	sol();
	return 0;
}
//a1004.cc
//generated automatically at Sun Nov 27 21:05:23 2016
//by xsthunder

