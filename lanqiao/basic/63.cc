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
const char N  = 'A'-1;
void A(int n  ){
	if(n==1){
		printf("%c",N+1);
	}
	else {
		A(n-1);
		printf("%c",N + n);
		A(n-1);
	}
}
void sol(){
	int n ; 
	 cin >>  n ; 
	  A(  n);
}
int main()
{
	sol();
	return 0;
}
//63.cc
//generated automatically at Sat Feb  4 14:57:43 2017
//by xsthunder

