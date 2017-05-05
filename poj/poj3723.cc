#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
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
typedef pair<int ,int > P;
const int cN = 5e4;
const int cR = 5e4+1e4;
int n,m,r;
//vector<P>v [cN];
int bost[cN];
struct edge{
	int f,t,c;
};
ostream  &operator << (ostream  &ou, edge a){
	ou<<"edge f:"<<a.f<<" t:"<<a.t<<" c:"<<a.c<<" end e ";
	return ou;
}
bool operator < (edge a,edge b){
	if(a.c==b.c){
		return a.f<b.f;
	}
	return !(a.c<b.c);
}
edge e[cN];;
int fa[cN];
void inp();
int cal();
int find(int x){
	if(fa[x])return fa[x]=find(fa[x]);
	else return x;
}
bool findu(int x,int y){
	x=find(x);
	y=find(y);
	return x==y;
}
void setu(int x,int y){
	while(fa[x])x=fa[x];
	while(fa[y])y=fa[y];
	if(bost[x]<bost[y])swap(x,y);
	fa[y]=x;
	bost[x]++;
}
int cal(){
	int ans = 0;
	sort(e,e+r);
	for(int i=0;i< r;i++){
		edge ce=e[i];
		if(!findu(ce.f,ce.t)){
			ans+=ce.c;
			setu(ce.f,ce.t);
			iF cout<<i<<ce<<ans<<endl;;
//			cout<<endl;
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		inp();
		cout<<((m+n)*10000-cal())<<endl;
	}
	return 0;
}
void inp(){
	for(int i =0;i<cN;i++){
	//	v[i].clear();
		bost[i]=0;
		fa[i]=0;
	}
	cin>>n>>m>>r;
	for(int i=0;i<r;i++){
		int a,b,c;
		cin>>a>>b>>c;
		b+=n;
		a++,b++;
#define adde(a,b,c) v[a].push_back(P(c,b))
	//	adde(a,b,c);
	//	adde(b,a,c);
		e[i]=(edge{a,b,c});
	}
}
//poj3723.cc
//generated automatically at Sun Apr 30 16:05:33 2017
//by xsthunder

