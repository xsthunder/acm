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
ostream&  operator << (ostream &out,const Point &a){ out<<'('<<a.first<<','<<a.second<<')'; return out; }
const int M=1e5;
void sol(){
	int x,i;
	cin>>x;
	i=0;
	LL xx=x;
	xx*=2;
	LL sum = 0 ;
	for(i =1;i<M;i++){
		sum+=i;
		if(sum>=x)break;
	}
	printf("%d\n", i);
}
int main()
{
	sol();
	return 0;
}
//C.cc
//generated automatically at Sat Mar 18 20:05:30 2017
//by xsthunder

