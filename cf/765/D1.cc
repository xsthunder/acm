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
int cnt=0;
map<int ,int >m;
int getid(int x){
	if(m.count(x))return m[x];
	else return m[x]=++cnt;
}
vector<int > g,h;

void sol(){
	int n ;
	cin>>n;
	g.push_back(0);
	h.push_back(0);
	for(int i = 0 ;i < n ;i++){
		int x;
		scanf("%d", &x);
		if(!m.count(x))h.push_back(x);
		g.push_back(getid(x));
	}
	int ans = 1;
	for(U i = 1; i<h.size();i++){
		if(g[h[i]]!=(int)i){
			ans=-1;
		}
	}
	if(ans<0)cout<<ans<<endl;
	else {
		cout<<cnt;
		cout<<endl;
		for(U i = 1;i<g.size();i++){
			if(i!=1)cout<<' ';
			cout<<g[i];
		}
		cout<<endl;
		for(U i = 1;i<h.size();i++){
			if(i!=1)cout<<' ';
			cout<<h[i];
		}
		cout<<endl;

	}
}
int main()
{
	sol();
	return 0;
}
//D1.cc
//generated automatically at Wed Feb 15 11:43:49 2017
//by xsthunder

