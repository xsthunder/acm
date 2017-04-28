#include<utility>
#include<queue>
#include<iostream>
using namespace std;
typedef pair<int ,int > P;
typedef unsigned U;
#define mk(a,b) make_pair(a,b)
#define iF if(Te)

const int N =5e3+1e1;
int n;
priority_queue<P , vector<P> ,greater<P> > pq;
vector<P>  v[N];
const int inf = 2e9;
int dist[N];
int dist2[N];
void inp();
void dij();
#ifdef XS
	const int Te =1;
#else
	const int Te =0;
#endif
void dij(){
	while(!pq.empty())pq.pop();
	pq.push(mk(0,0));
	dist[0]=0;
	while(!pq.empty()){
		P cur = pq.top();
		pq.pop();
		int w = cur.first;
		int t = cur.second;
		if(dist2[t]<w)continue;
		for(U i=0;i<v[t].size();i++){
			P nxt = v[t][i];
			int u= nxt.first;
			int ww = nxt.second;
			int d2=dist[t]+ww;
			iF cout<<dist[u]<<' '<<u<<' '<<dist[t]<<' ' <<ww<<endl;
			if(dist[u]>d2){
				iF cout<<dist[u]<<' '<<u<<endl;
				swap(d2,dist[u]);
				pq.push(mk(dist[u],u));
				//cout<<"dist"<<u<<":"<<dist[u]<<endl;
			}
			if(dist2[u]>d2&&dist[u]<d2){
				dist2[u]=d2;
				pq.push(mk(dist[u],u));
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	dij();
	cout<<dist2[n-1]<<endl;
//	cout<<dist[n-1]<<endl;
	return 0;
}
void inp(){
	for(int i =0;i<N ;i++){
		v[i].clear();
		dist[i]=inf;
		dist2[i]=inf;
	}
	int r;
	cin>>n>>r;
	while(r--){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		v[a].push_back(mk(b,c));
		v[b].push_back(mk(a,c));
	}
}
