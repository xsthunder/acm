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
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<' '<<*(begin+i); } printf("\n"); }
struct V{
	int p;
	int l;
	int d;
	bool operator < (V a){
		if(this->d!=a.d)return this->d>a.d;
		else if(this->l!=a.l)return this->l<a.l;
		return this->p>a.p;
	}
};
vector<V > VV;
void dfs(int cst,int d){
	for(V v:VV){
		if()
	}
}
void sol(){
	int n;scanf("%d",&n);
	while(n--){
		int p,l,d;
		scanf("%d%d%d",&p,&l,&d);
		VV.push_back(V{p,l,d});
	}
	sort(VV.begin(),VV.end());
	dfs(0,VV.front().d);
}
int main()
{
	sol();
	return 0;
}
//t1002.cc
//generated automatically at Fri Nov 18 23:36:18 2016
//by xsthunder

