#include<iostream>
#include<utility>
#include<queue>
#include<iomanip>
using namespace std;
#define iF if(Te)
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;

void inp();
void dij();

const int N= 5e3+1e1;
int n;
typedef pair<int ,int > P;
int d[N];
int dist[N];
vector<P > v[N];
priority_queue<P, vector<P> ,greater<P> >pq;

void dij(){
	while(!pq.empty())pq.pop();
	d[0]=0;
	pq.push(P(0,0));
	while(!pq.empty()){
		P cur = pq.top();
		pq.pop();
		int d2 = cur.first;
		int f = cur .second;
		if(d2>dist[f])continue;
		for(U i=0;i<v[f].size();i++){
			P e = v[f][i];
			int w =e.first;
			int t = e.second;
			int &sho = d[t];
			int &sho2=dist[t];
			int dn = d2+w;
			iF cout<<d2<<' '<<f<<endl<<','<<sho<<' '<<sho2<<endl<< ','<<w<<' '<<t<<' '<<dn<<endl<<endl;
			if(sho>dn){
#define pqp(a) pq.push(P(a,t))
				swap(sho,dn);
				pqp(sho);
			}
			if(dn<sho2&&dn>sho){
				sho2=dn;
				pqp(sho2);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	dij();
	cout<<dist[n-1]<<endl;
	return 0;
}
void inp(){
	int inf =2e9;
	for(int i=0;i< N;i++){
		v[i].clear();
		dist[i]=inf;
		d[i]=inf;
	}
	int r;
	cin>>n>>r;
	while(r--){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		v[a].push_back(P(c,b));
		v[b].push_back(P(c,a));
	}
}
//poj3255.my.cc
//generated automatically at Sat Apr 29 10:36:31 2017
//by xsthunder

