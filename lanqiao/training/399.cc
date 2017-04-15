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
int c(int k,int n ){
	if(k==0||k==n)return 1;
	else {
		return c(k,n-1)+c(k-1,n-1);
	}
}
void sol(){
	int k,n;
	cin>>k>>n;
	cout<<c(k,n);
}
int main()
{
	sol();
	return 0;
}
//399.cc
//generated automatically at Fri Feb 10 20:55:07 2017
//by xsthunder

