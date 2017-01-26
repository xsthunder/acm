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
	ULL n ,m , k, x, y;
	cin>>n>>m>>k>>x>>y;
	ULL r = (k/m/n)%2;
	ULL Min = k/m/n/2;
	ULL Max=0;
	ULL X,Y;
	X=(k/m/n)+(k%(m*n))?1:0;
	Y=k%(m*n);
	if(r==0){
		Max= Min;
	}
	else {
		Max = Min +1;
		X=m-X-1;
	}
}
int main()
{
	sol();
	return 0;
}
//C.cc
//generated automatically at Fri Jan 20 01:09:20 2017
//by xsthunder

