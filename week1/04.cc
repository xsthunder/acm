const bool test=0;
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
const int N=2e6+10;
int d[N];
set<pair<int ,int >>sp;
struct vet{
	int i;
	int d;
};
void read(int &u,int &v){
	if(u>v)swap(u,v);
}
void sol(){
	memset(d,-1,sizeof(d));
	int m,n;scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		read(u,v);
		if(u!=v)sp.insert(make_pair(u,v));
	}
	int s;scanf("%d",&s);
	queue <vet> q;
	for(int i=1;i<=n;i++){
		int u=min(i,s);
		int v=max(i,s);
		if(u!=v&&!sp.count(make_pair(u,v)))q.push((vet){i,1});
		d[i]=1;
	}
	IF cout<<"sp.size()"<<sp.size()<<endl;
	IF cout<<"q.size()"<<q.size()<<endl;
	 while(!q.empty()){
		IF cout<<q.size()<<endl;;
		vet x=q.front();q.pop();
		int vi=x.i;int vd=x.d;
		IF cout<<vi<<' '<<vd<<endl;
		for(int i=1;i<=n;i++){
				int u=min(i,s);
				int v=max(i,s);
				if(!sp.count(make_pair(u,v))&&d[i]==-1&&vi!=i){
					q.push((vet){i,vd+1});
					d[i]=vd+1;
				}
		}
		for(int i=1;i<=n;i++){
			if(i!=s)printf("%d ",d[i]);
		}
		printf("\n");
	 }
}
	 int main()
	 {
		 int t;
		 scanf("%d",&t);
		 while(t--){
			 sol();
		 }
		 return 0;
	 }
	 //04.cc
	 //generated automatically at Thu Oct 13 12:22:20 2016
	 //by xsthunder

