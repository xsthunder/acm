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
const int N=505;
struct E{
	int c1;
	int c2;
	int cst;
};
struct UnSet{
	int parent[N];
	int urank[N];
	int n;
	void init(int n){
		this->n=n;
		for(int i=0;i<=n;i++){
			parent[i]=i;
			urank[i]=0;
		}
	}
	int find(int x){
		if(parent[x]==x)return x;
		else return parent[x]=find(parent[x]);
	}
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(urank[x]<urank[y]){
			parent[x]=y;
		}
		else {
			parent[y]=x;
			if(urank[x]==urank[y])urank[x]++;
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
};
bool operator< (E a,E b){
	if(a.cst!=b.cst)return a.cst<b.cst;
	else {
		if(a.c1!=b.c1)return a.c1<b.c1;
		else {
			return  a.c2<b.c2;
		}
	}
}
vector<E> vE;
int n;
int cal(int c){
	UnSet US;
	US.init(n);
	int ans=0;
	int cnt=0;
	for(E e:vE){
		int c1=e.c1,c2=e.c2,cst=e.cst;
		if(c1!=c&&!US.same(c1,c2)){
		//	cout<<cst<<c1<<c2;
			ans+=cst;
			US.unite(c1,c2);
			cnt++;
		}
	}
	return cnt==n-2?ans:inf;
}
void sol(){
	int m;
	scanf("%d%d",&n,&m);
	while(m--){
		int c1,c2,cst,s;
		scanf("%d%d%d%d",&c1,&c2,&cst,&s);
		if(s==1)cst=0;
		vE.push_back(E{c1,c2,cst});
	}
	sort(vE.begin(),vE.end());
	int max0=1;
	vector<int > ans;
	for(int i=1;i<=n;i++){
		int tmp=cal(i);
		IF cout<<tmp<<' '<<i<<endl;
		if(max0==tmp){ans.push_back(i);
		}
		else if(max0>tmp)continue;
		else if(max0<tmp){
				ans.clear();
				max0=tmp;
				ans.push_back(i);
//				IF cout<<tmp<<' '<<i<<endl;
		}
//		IF break;
	}
	bool fflag=0;
	for(int x:ans){
		if(fflag)printf(" ");
		fflag=1;
		printf("%d",x);
	}

}
int main()
{
	sol();
	return 0;
}
//t1001.cc
//generated automatically at Fri Nov 18 02:40:41 2016
//by xsthunder

