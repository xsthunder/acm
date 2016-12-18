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
const int N=1e6;
vector<int > vii[N];;
ll dat[N];
//bool vis[N];
vector<int > ans;
ll enter(int root,bool is_root){
	if(is_root){
		if(vii[root].size()==1){
			return enter(vii[root][0],1);
		}
		else if(vii[root].size()==0){
			return -1;
		}
		else {
			for(int x:vii[root]){

			}
		}
	}
	else {
		ll part_sum=0;
		for(int x:vii[root]){
			part_sum+=enter(x,0);
		}
		part_sum+=dat[root];
		return part_sum;
	}
}
void sol(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&dat[i]);
	}
	for(int i=1;i<=n-1;i++){
		int x,y;
		scanf("%d%d", &x,&y);
		vii[x].push_back(y);
		vii[y].push_back(x);
	}
	cout<<enter(0,1)<<endl;
}
int main()
{
	sol();
	return 0;
}
//D.cc
//generated automatically at Thu Dec 15 00:01:14 2016
//by xsthunder

