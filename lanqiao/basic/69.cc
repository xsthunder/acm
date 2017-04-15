const bool TEST=1;
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
void sol(){
	int n; 
	cin >>n ;
	priority_queue<int ,vector<int > ,greater<int > > pq;
	for(int i = 0 ;i < n;i++){
		int x ;
		scanf("%d", &x);
		pq.push(x);
	}
	ULL res= 0 ;
	while(pq.size()!=1){
		int x=pq.top();
		pq.pop();
		int x2= pq.top();
		pq.pop();
		int sum = x +x2 ;
		res+=sum;
		pq.push(sum);
	}
	cout<<res<<endl;
}
int main()
{
	sol();
	return 0;
}
//69.cc
//generated automatically at Wed Feb  8 10:00:20 2017
//by xsthunder

