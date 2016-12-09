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
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
ll A[100+10];
void sol(){
	int n;int m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&A[i]);
	int cnt=0;
	int start;
	start=(n-m%n)%n;
	cnt++;printf("%lld",A[start]);
	for(int i=(start+1)%n;;i++,i=i%n){
		if(cnt==n)return;
		printf(" %lld",A[i]);
		cnt++;
	}
}
int main()
{
	sol();
	return 0;
}
//bsc_1008.cc
//generated automatically at Tue Nov  1 20:01:59 2016
//by xsthunder

//AC at Tue Nov  1 21:22:29 2016
 
