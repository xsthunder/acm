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
const bool test=1;
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
void pA(int *begin,int n){
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
	sort(A,A+n);
	for(int i=0;i<n-1;i++){
		A[i+1]=A[i]+A[i+1];
		sum+=A[i+1];
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

