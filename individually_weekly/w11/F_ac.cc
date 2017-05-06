#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int ,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		inp();
	}
	return 0;
}
const int N = 1e5+1e4;
vector<int > v[N];
int dp[N];
const int inf = 1e9;
void dij(){
	priority_queue<P > pq;
	pq.push(P(0,0));
	while(!pq.empty()){
		P p = pq.top();
		pq.pop();
		int d=p.first;
		int cur = p.second;
		//iF cout<<d<<' '<<cur<<endl;;
		if(d>=dp[cur]){
			for(U i=0;i<v[cur].size();i++){
				int nxt= v[cur][i];
			//	cout<<nxt<<' '<<dp[nxt]<<' '<<d+1<<endl;
				if(dp[nxt]>d+1){
					dp[nxt]=d+1;
					pq.push(P(dp[nxt],nxt));
		//			pA(dp,10,2);
				}
			}
		}
	}
}
void inp(){
	int n,d;
	cin>>n>>d;
	for(int i =0;i<n;i++){
		dp[i]=inf;
		v[i].clear();
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
#define push(a,b) v[a].push_back(b)
		push(a,b);
		push(b,a);
	}
	dp[0]=0;
	dij();
	int cnt =0;
	for(int i=0;i<n;i++){
		if(dp[i]>d)cnt++;
	}
	cout<<cnt<<endl;
}
//F.cc by xsthunder at Sat May  6 09:19:20 2017

//AC at Sat May  6 09:42:23 2017
 
