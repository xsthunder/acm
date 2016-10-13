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
struct vet{
	int i;
	int d;
};
void read(int &u,int &v){
	if(u>v)swap(u,v);
}
void sol(){
	set<pair<int ,int >>sp;
	memset(d,-1,sizeof(d));
	int m,n;scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		read(u,v);
		if(u!=v)sp.insert(make_pair(u,v));
	}
	IF for(point x:sp)cout<<x.first<<'p'<<x.second<<endl;
	int s;scanf("%d",&s);
	queue <vet> q;
	set<int >si;
//	IF pA(d+1,n);
	for(int i=1;i<=n;i++){
		int u=min(i,s);
		int v=max(i,s);
		if(u!=v&&!sp.count(make_pair(u,v))){q.push((vet){i,1});
		d[i]=1;
		}
		else {
			if(u!=v)si.insert(i);
		}
	}
	d[s]=0;
	IF pA(d+1,5);
	IF {
		vet tmp=q.front();
		cout<<"i,d "<<tmp.i<<tmp.d<<endl;
	}
	//checked
	IF cout<<"sp.size()"<<sp.size()<<endl;
	while(!q.empty()){
		IF cout<<"q.size()"<<q.size()<<endl;
		//IF cout<<q.size()<<endl;;
		vet x=q.front();q.pop();
		int vi=x.i;int vd=x.d;
		IF cout<<"vi,vd "<<vi<<' '<<vd<<endl;
		IF cout<<"si.size()"<<si.size()<<endl;
		if(si.empty())break;
		for(int i:si){
				int u=min(i,vi);
				int v=max(i,vi);
				if(!sp.count(make_pair(u,v))&&d[i]==-1&&vi!=i){
					IF cout<<"u,v "<<u<<' '<<v<<endl;
					q.push((vet){i,vd+1});
					d[i]=vd+1;
					si.erase(i);
				}
		}
	IF pA(d+1,5);
	 }
	bool fst=1;
	 FI for(int i=1;i<=n;i++){
		 IF cout<<s<<endl;
		 if(i!=s){
			IF cout<<i;
			 if(fst){
				 printf("%d",d[i]);
				 fst=0;
			 }
			 else {
				 printf(" %d",d[i]);
			 }
		 }
	 }
	 printf("\n");
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

//AC at Thu Oct 13 18:02:47 2016
 
