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
int n;
int c1,c2;
const int maxn=500+10;
int Ps[maxn];
vector<point> VP[maxn];
pair<int ,int > mk(int x,int y){
	return make_pair(x,y);
}
int vis[maxn];
int num[maxn];
int pes[maxn];
void dij(){
	fill(vis,vis+maxn,inf);
	priority_queue<point > pq;
	int _min=inf;
	for(point x:VP[c1]){
		if(_min>x.second){
			pq.clear();
			pq.push(mk(x.second,x.first));
		}
		else if(_min==x.second){
			pq.push(mk(x.second,x.first));
		}
	}
	while(!pq.empty()){
		point x=pq.top;pq.pop();
		int d=x.first;int index=x.second;
		if(vis[index]<d){
			continue;
		}
		else if(vis[index]==d){
			num[index]++;
			per[index]++;
		}
		else if(vis[index]>d){
			
		}
	}
}
void sol(){
	int m;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++){
		scanf("%d",&Ps[i]);
	}
	while(m--){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		VP[x].push_back(mk(y,c));
		VP[y].push_back(mk(x,y));
	}
	dij();
}
int main()
{
	sol();
	return 0;
}
//a1003.cc
//generated automatically at Sat Nov 19 23:57:19 2016
//by xsthunder

