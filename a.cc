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
	int n;
	scanf("%d",&n);
	char ans[][10]={
		"WHITE",
		"BLACK"
	};
	for(int t=1;t<=n;t++){
		int w,b;
		scanf("%d%d",&w,&b);
		printf("Case #%d: %s\n",t, ans[b&1]);
	}
}
int main()
{
	sol();
	return 0;
}
//a.cc
//generated automatically at Sat Dec 10 20:55:51 2016
//by xsthunder

