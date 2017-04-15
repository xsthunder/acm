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
void A(int cur,int n, bool f){
	if(cur==n){
		printf("sin(%d)",n);
		return ;
	}
	else {
		char x = f?'+':'-';
		printf("sin(%d%c",cur,x);
		A(cur+1,n,!f);
		printf(")");
	}
}
void S(int cur, int n ){
	if(cur==n){
		if(cur!=1)printf("(");
		A(1,1,0);
		printf("+%d",n);
		if(cur!=1)printf(")");
		return ;
	}
	else {
		if(cur!=1)printf("(");
		S(cur+1,n);
		A(1,n-cur+1,0);
		printf("+%d",cur);
		if(cur!=1)printf(")");
	}
}
void sol(){
	int n;
	cin>>n;
	//A(1,n,0);
	S(1,n);
}
int main()
{
	sol();
	return 0;
}
//62.cc
//generated automatically at Sat Feb  4 14:04:09 2017
//by xsthunder

