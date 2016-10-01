#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
#include<cassert>
const int inf=0x7fffffff;
#define IF if(test)
const bool test=0;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <class T>
void pA(T *begin,int n){
	for(int i=0;i<n;i++){
		printf("%d" ,*(begin+i));
	}
	printf("\n");
}
int n;
const int N=2e4+100;
ll A[N];
ll Tre(){
	ll sum=0;
	priority_queue<ll, vector<ll> ,greater<ll> > s(A,A+n);
	ll tmp;
	for(int i=0;i<n-1;i++){
		tmp=0;
		tmp+=s.top();s.pop();
		IF cout<<tmp<<' ';
		tmp+=s.top();s.pop();
		IF cout<<tmp<<endl;
		sum+=tmp;
		s.push(tmp);
	}
	return sum;
}
void solve(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%lld", A+i);
		}
		printf("%lld\n",Tre());
	}
}
int main()
{
	solve();
	return 0;
}
//poj3253.cc
//generated automatically at Thu Sep 29 22:14:48 2016
//by xsthunder

