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
void sol(){
	int x;scanf("%d",&x);
	int c=x%10;x/=10;
	int b=x%10;x/=10;
	int a=x%10;x/=10;
	while(a--){
		printf("B");
	}
	while(b--){
		printf("S");
	}
	for(int i=1;i<=c;i++)printf("%d",i);
	printf("\n");
}
int main()
{
	sol();
	return 0;
}
//bsc_1006.cc
//generated automatically at Tue Nov  1 19:42:34 2016
//by xsthunder

//AC at Tue Nov  1 19:47:01 2016
 
