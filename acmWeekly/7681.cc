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
const int MAX=1e4;
const int MIN=0;
int aI=MAX,aA=MIN;
int bI=MAX,bA=MIN;
void inp();
void sol();
int main()
{
	inp();
	sol();
	return 0;
}
void sol(){
	
}
void inp(){
	int n; 
	scanf("%d",&n);
	for(int i = 0 ;i < n ;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		aI=min(aI,a);
		aA=max(aA,a);
		bI=min(bI,b);
		bA=max(bA,b);
	}
}
//7681.cc
//generated automatically at Sun Mar  5 18:02:18 2017
//by xsthunder

