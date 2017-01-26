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
void dfs(int dep, string s, char c){
	s+=c;
	if(dep==4){
		cout<<s<<endl;
		return ;
	}
	dep++;
	dfs(dep,s,'0');
	dfs(dep,s,'1');
}
void sol(){
	int dep=0;
	dfs(dep,"",'0');
	dfs(dep,"",'1');
}
int main()
{
	sol();
	return 0;
}
//6.cc
//generated automatically at Tue Jan 17 11:14:02 2017
//by xsthunder

