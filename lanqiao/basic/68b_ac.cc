const bool TEST=0;
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
typedef vector<set< int > > Vs;
vector< vector< int > >ans;
int n ;
void dfs(int dep,Vs vs,vector<int> curans){
	if(dep==n){
		ans.push_back(curans);
		return ;
	}
	set<int > &s = vs[dep];
	for(set<int > ::iterator it=s.begin();it!=s.end();it++){
		Vs vs1=vs;
		curans.push_back(*it);
		for(int dep1=dep+1,x=*it;dep1<n;dep1++){
			set<int > &s1=vs1[dep1];
			if(s1.count(x))s1.erase(x);
		}
		for(int dep2=dep+1,x=*it+1;dep2<n&&x<=n;dep2++,x++){
			set<int > &s2=vs1[dep2];
			if(s2.count(x))s2.erase(x);
		}
		for(int dep3=dep+1,x=*it-1;dep3<n&&x>0;dep3++,x--){
			set<int > &s3=vs1[dep3];
			if(s3.count(x))s3.erase(x);
		}
		dfs(dep+1,vs1,curans);
		curans.pop_back();
	}
}
int cnt(){
	int res=0;
	for( U i = 0 ;i < ans.size();i++){
		for( U j = 0 ;j < ans.size();j++){
			res++;
			if(i==j){
				res--;
				continue;
			}
			if(ans[i].size()!=ans[j].size()){
				printf("invalid length");exit(2);
			}
			for(U k = 0 ;k< ans[i].size();k++){
				if(ans[i][k]==ans[j][k]){
					res--;break;
				}
			}
		}
	}
	return res;
}
void sol(){
	cin>>n;
	Vs vs;
	vs.resize(n);
	for(int i = 0;i< n;i++){
		set<int > &s = vs[i];
		for(int j = 0 ;j< n;j++){
			int x ;
			scanf("%d", &x);
			if(x)s.insert(j+1);
		}
	}
	vector<int > curans;
	dfs(0,vs,curans);
	IF for(U i = 0;i< ans.size();i++){
		for(U j = 0;j<ans[i].size();j++){
			printf(" %d", ans[i][j]);
		}
		cout<<endl;
	}
	cout<<cnt();
}
int main()
{
	sol();
	return 0;
}
//68b.cc
//generated automatically at Wed Feb  8 09:13:53 2017
//by xsthunder

//AC at Wed Feb  8 09:57:26 2017
 
