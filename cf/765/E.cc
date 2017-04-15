const bool TEST=1;
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
#include<sstream>
#include<stack>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
const int N = 2e5+1000;
set<int >  vii[N];;
struct node{
	int mx;
	set<int > si;
}Node[N];
int done[N];
bool flag=0;
Point tra(int x  ) {
	int cnt=0;
	//int bef=x;
	while(vii[x].size()==1){
		cnt++;
		if(x==*(vii[x].begin())){
			flag=1;
			exit(0);
		}
		//bef=x;
		done[x]=cnt;
		x=*(vii[x].begin());
	}
	return MK(x,cnt);
}
void sol(){
	int n ; 
	for(int i = 0 ; i < n-1 ;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		vii[a].insert(b);
		vii[b].insert(a);
	}
	set<Point > sp;
	for(int i = 1;i<=n;i++){
		if(vii[i].size()==1){
			Point nod=tra(i);
		}
	}
}
int main()
{
	sol();
	return 0;
}
//E.cc
//generated automatically at Tue Feb 14 18:18:23 2017
//by xsthunder

