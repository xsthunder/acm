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
	int a,p;
	int ansa,ansp;
	bool flag=0;
	while(scanf("%d%d",&a,&p)!=EOF){
		if(a==0||p==0)continue;
		if(flag){
			printf(" ");
		}
		ansp=p-1;
		ansa=a*p;
		flag=1;
		printf("%d %d",ansa,ansp);
	}
	if(!flag)printf("0 0");
	printf("\n");
}
int main()
{
	sol();
	return 0;
}
//bsc_1010.cc
//generated automatically at Tue Nov  1 21:45:35 2016
//by xsthunder

//AC at Tue Nov  1 22:39:25 2016
 
