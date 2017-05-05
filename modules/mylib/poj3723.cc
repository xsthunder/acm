#include<iostream>
#include<algorithm>
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
const int cE = 5e4+1e4;
const int cN = 1e4+1e4;
int n,m,r;
int V;
int E;
const int cV = 3e4;
struct edge{int f,t,c;};
edge es[cE];
int par[cV];
int rank[cV];

bool operator < (const edge &a,const edge &b){
	if(a.c==b.c){
		if(a.f==b.f)return a.t<b.t;
		else return a.f<b.f;
	}
	else return a.c<b.c;
}

int kruskal(){
	sort(es,es+E);
	init_union_find(V);
	int ans=0;
	for(int i=0;i<E;i++){
		edge e = es[i];
		if(!same(e.f,e.f)){
			unite(e.f,e.t);
			ans+=e.c;
		}
	}
	return ans;
}


//unionSet core starts
void initUnionSet(int V){
	for(int i=0;i<V;i++){
		par[i]=i;
		rank[i]=0;
	}
}
int same(int x){
	if(par[x]==x)return e;
	else return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return ;
	else {
		if(rank[x]<rank[y])swap(x,y);
		par[y]=x;
		rank[x]++;
	}
}
//unionSet core ends


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		inp();
		cout<<10000*(n+m)+kruskal()<<endl;
	}
	return 0;
}
void inp(){
	cin>>n>>m>>r;
	E=r;
	initUnionSet(cN);
	for(int i=0;i<r;i++){
		int a,b,c;
		cin>>a>>b>>c;
		b+=cN;
		es[i]=edge{a,b,-c};
	}
}
//poj3723.cc
//generated automatically at Sun Apr 30 17:36:43 2017
//by xsthunder

