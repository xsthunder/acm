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

	int _min=10000;
	int _max=-10000;
	int n;
	LL ans=0;;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		_min=min(_min,x);
		_max=max(_max,x);
		ans+=x;
	}
	cout<<_max<<endl<<_min<<endl<<ans<<endl;
}
int main()
{
	sol();
	return 0;
}
//7.cc
//generated automatically at Tue Jan 17 13:30:43 2017
//by xsthunder

