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
#define BL(nod) (nod)*2,(t[(nod)]).l,((t[(nod)]).l+t[(nod)].r)/2
#define BR(nod) (nod)*2+1,(t[(nod)].l+t[(nod)].r)/2+1,t[(nod)].r
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
const int N  = 1e5;
int n; 
struct NODE{
	int l;
	int r;
	bool same;
	Point p;
}t[4*N];
int a[N*4];
LL ans[N+10];
int curi;
int cur;
int _min;
int D;
int CNT=0;
const int ROOT=1;
namespace std{
bool operator< (const Point &a,const Point &b){
	if(a.first<b.first)return 1;
	else if(a.first==b.first){
		return a.second>b.second;
	}
	else return 0;
}
}
void pri(){
	for(int i = 1;i<=n;i++){
		printf("%lld\n",ans[i]);
	}
}
inline void log(){
	FI return ;
	if(CNT==3)exit(0);
	CNT++;
	IF if(1){
		for(int i = 1;i< 5;i++){
			printf("i:%d l:%d r:%d p:(%d,%d) same:%d\n",i,t[i].l,t[i].r,t[i].p.first,t[i].p.second, t[i].same);
		}
	}
}
NODE build(int ind,int l,int r){
	t[ind].l=l;
	t[ind].r=r;
	if(l==r){
		t[ind].same=1;
		t[ind].p=MK(a[l],l);
		return t[ind];
	}
	NODE c1,c2;
	c1=build(BR(ind));
	c2=(build(BL(ind)));
	if(c1.same&&c2.same&&c1.p.first==c2.p.first){
		t[ind].same=1;
	}
	t[ind].p=max(c1.p,c2.p);
	return t[ind];
}
NODE upg(int nod ,int l,int r){
	NODE &x=t[nod];
	IF cout<<"upg "<<nod<<' '<<l<<' '<<r<<endl;
	if(x.p.first<=_min)return x;
	if(x.r<l)return x;
	else if (x.l>r)return x;
	else if(l<=x.l&&x.r<=r&&x.same){
		LL times=x.p.first-_min;
		LL cnt=x.r-x.l+1;
		ans[curi]+=cnt*times;
		x.p.first-=times;
		return x;
	}
	else {
		NODE c1,c2;
		c1=upg(nod*2,l,r);
		c2=upg(nod*2+1,l,r);
		x.p=max(c1.p,c2.p);
		if(c1.p.first==c2.p.first&&
				c1.same&&c2.same){
			x.same=1;
		}
		return x;
	}
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
	NODE &x=t[1];
	log();
	while(x.p.first!=0){
		IF cout<<"-------------"<<endl;
		IF pri();
		curi=x.p.second;
		cur=x.p.first;
		_min=que(ROOT,1,curi-1).first;
		upg(ROOT,curi,n);
		IF {
			printf("curi:%d, cur:%d, _min:%d\n",curi,cur,_min);
		}
		log();
//		exit(0);
		x=t[1];
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

