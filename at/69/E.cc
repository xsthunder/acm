const bool TEST=0;
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
#include<sstream>
#include<stack>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
const int N  = 1e5;
struct NODE{
	int l;
	int r;
	Point p;
}t[4*N];
int a[N*4];
int ans[N+10];
int curi;
int D;
namespace std{
bool operator< (const Point &a,const Point &b){
	if(a.first<b.first)return 1;
	else if(a.first==b.first){
		return a.second>b.second;
	}
	else return 0;
}
}
Point build(int ind,int l,int r){
	t[ind].l=l;
	t[ind].r=r;
	if(l==r){
		return t[ind].p=MK(a[l],l);
	}
	return t[ind].p=max(build(2*ind,l,(l+r)/2),(build(2*ind+1,(l+r)/2+1,r)));
}
Point upg(int nod ,int index){
	NODE &x=t[nod];
	IF if(nod==1)cout<<"upg"<<index<<endl;
	if(x.l==x.r&&x.l==index){
		x.p.first--;
		return x.p;
	}
	if(x.l<=index&&x.r>=index){
		return x.p=max(upg(nod*2,index),upg(nod*2+1,index));
	}
	else return x.p;
}
Point que(int nod,int l,int r){
	if(l>r)return MK(0,inf);
	NODE x=t[nod];
	if(l<=x.l&&x.r<=r)return x.p;
	if(x.r<l||x.l>r){
//		cout<<"returing (0,inf) "<<nod<<' ';
//		printf("(%d,%d)",x.l,x.r);
//		printf("l,r:(%d,%d)\n",l,r);
		return MK(0,inf);

	}
	return max(que(nod*2,l,r),que(nod*2+1,l,r));
}
int n; 
void pri(){
	for(int i = 1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
}
void sol(){
	cin>>n;
	for(int i = 1 ;i<= n;i++){
		int x;
		scanf("%d" , & x);
		a[i]=x;
	}
	D=1;
	while(n>(1<<D)){
		D++;
	}
	build (1,1,1<<D);
	IF if(0){
		for(int i = 1;i< 5;i++){
			printf("i:%d l:%d r:%d p:(%d,%d)\n",i,t[i].l,t[i].r,t[i].p.first,t[i].p.second);
		}
	}
	NODE &x=t[1];
	while(x.p.first!=0){
		ans[x.p.second]++;
		IF cout<<"-------------"<<endl;
		Point y = que(1,x.p.second+1,n);
		IF printf("(%d,%d)\n",y.first,y.second);
		if(y.first==x.p.first){
			upg(1,y.second);
		}
		else upg(1,x.p.second);
		IF pri();
	IF {
		for(int i = 1;i< 5;i++){
			printf("i:%d l:%d r:%d p:(%d,%d)\n",i,t[i].l,t[i].r,t[i].p.first,t[i].p.second);
		}
	}
	}
	pri();
}
int main()
{
	sol();
	return 0;
}
//E.cc
//generated automatically at Sun Feb 19 10:43:33 2017
//by xsthunder

