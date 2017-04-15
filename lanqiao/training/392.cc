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
ULL gcd(ULL a,ULL b){
	return b?gcd(b,a%b):a;
}
ULL lcm(ULL a,ULL b){
	return a*b/gcd(a,b);
}
void sol(){
	ULL a,b;
	cin>>a>>b;
	cout<<lcm(a,b);
}
int main()
{
	sol();
	return 0;
}
//392.cc
//generated automatically at Fri Feb 10 20:59:51 2017
//by xsthunder

