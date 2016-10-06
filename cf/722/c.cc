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
#define gts(s) fgets((s),sizeof(s),stdin)
const bool test=1;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pA(int *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
const int AN=3e5;
struct line
{
	int left,right;//左端点、右端点
	ll sum;
	bool v;
};
struct line a[AN];
int sum;
int n;
//建立
void build(int s,int t,int n)
{
	int mid=(s+t)/2;
	a[n].left=s;
	a[n].right=t;
	if (s==t) return;
	a[n].left=s;
	a[n].right=t;
	build(s,mid,2*n);
	build(mid+1,t,2*n+1);
} 
void sol(){
	scanf("%d", &n);
	int d;
	int s;
	if(n%2==1){
		
	}
	else {
	}
	for(int i;i<n;i++){
	}
}
int main()
{
	sol();
	return 0;
}
//c.cc
//generated automatically at Sat Oct  1 23:37:38 2016
//by xsthunder

