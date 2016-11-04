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
bool sol(){
	ll a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	return a+b>c;
}
int main()
{
	int t;scanf("%d", &t);
	for(int i=1;i<=t;i++)printf("Case #%d: %s",i,sol()?"true\n":"false\n");
	return 0;
}
//bsc_1011.cc
//generated automatically at Wed Nov  2 16:55:15 2016
//by xsthunder

