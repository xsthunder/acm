#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
#define mk(i,j) make_pair(i,j)
int n;
void inp();
const int N = 10+5;
typedef unsigned int U;
typedef pair<U,U> P;
priority_queue<P,vector<P>,greater<P> > pq;
U dp[N];
map<U,U> mii[N];
U vis[N];
U _min;
bool valid[N];
void dea();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n){
		inp();
		dea();
		cout<<_min<<endl;
	}
}
void dea(){
	dp[0]=0;
	int cnt = 0;
	pq.push(mk(0,0));
	while(cnt!=n&&!pq.empty()){
		P p = pq.top();

	//	cout<<p.first<<' '<<p.second<<endl;
		pq.pop();
		vis[p.second]=1;
		cnt++;
		if(valid[p.second])_min=min(_min,(U)p.first);
		for(auto x:mii[p.second]){
	//		cout<<x.first<<','<<x.second<<endl;
		dp[x.first]=min(dp[x.first],dp[p.second]+x.second);
			pq.push(mk(dp[x.first],x.first));
		}
	}
}
void inp(){
	memset(dp,-1,sizeof(dp));
	memset(vis,0,sizeof(vis));
	_min=-1;
	while(!pq.empty())pq.pop();
	for(int i =0 ;i <n;i++){
		mii[i].clear();
		int m,p;
		cin>>m>>p;
		valid[i]=p;
		while(m--){
			int s,l;
			cin>>s>>l;
			mii[i][s]=l;
		}
	}
}
