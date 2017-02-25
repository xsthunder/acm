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
ostream&  operator << (ostream &out,const Point &a){
	out<<'('<<a.first<<','<<a.second<<')';
	return out;
}
int n; 
void sol(){
	cin>>n;
	priority_queue<Point > pq;
	for(int i = 1 ;i<= n;i++){
		int x;
		scanf("%d" , & x);
		pq.push(MK(x,i));
	}
	int cnt=0;
//	while(!pq.empty()){
//		cout<<pq.top()<<endl;;
//		pq.pop();
//	}
	while(pq.top().first!=0){//reduce p1;
		Point p1,p2;
		p1=pq.top();pq.pop();
		p2=pq.top();pq.pop();
		IF cout<<p1<<p2<<endl;;
		ans[p1.second]++;
		if(p1.first==p2.first){
			swap(p1,p2);
		}
		p1.first--;
		pq.push(p1);
		pq.push(p2);
		IF {
			cnt++;
			if(cnt==30)exit(1);
		}
	}
	for(int i =1;i<=n;i++){
		printf("%d\n", ans[i]);
	}
}
int main()
{
	sol();
	return 0;
}
//E.cc
//generated automatically at Sun Feb 19 10:43:33 2017
//by xsthunder

