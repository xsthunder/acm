

int E,V;
const int cE  = 2e5;
const int cV=2e5;


//unionSet defination starts
#include<algorithm>
using namespace std;


int par[cV];
int USrank[cV];
//unionSet defination ends


//unionSet core starts
void initUnionSet(int V){
	for(int i=0;i<V;i++){
		par[i]=i;
		USrank[i]=0;
	}
}
int find(int x){
	if(par[x]==x)return x;
	else return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y)return ;
	else {
		if(USrank[x]<USrank[y])swap(x,y);
		par[y]=x;
		USrank[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}
//unionSet core ends


//kruskal defination starts
struct edge{int f,t,c;};
edge es[cE];


//kruskal defination ends

//kruskal core starts
bool operator < (const edge &a,const edge &b){
	if(a.c==b.c){
		if(a.f==b.f)return a.t<b.t;
		else return a.f<b.f;
	}
	else return a.c<b.c;
}

int kruskal(){
	sort(es,es+E);
	initUnionSet(V);
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
//kruskal core ends
int main(){

	return 0;
}
