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
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<' '<<*(begin+i); } printf("\n"); }
int a[6];
int n[6];
void sol(){
	int t;scanf("%d",&t);
	bool p=0;
	while(t--){
		int x;scanf("%d",&x);
		int rest=x%5;
		switch(rest){
			case 0:if(x%2==0){a[1]+=x;n[1]++;}break;
			case 1:if(p==1)x=-x;p=!p;a[2]+=x;n[2]++;break;
			case 2:a[3]++;n[3]++;break;
			case 3:a[4]+=x;n[4]++;break;
			case 4:a[5]=max(a[5],x);n[5]++;break;
		}
	}
	bool fflag=0;
	for(int i=1;i<=5;i++){
		if(fflag)printf(" ");
		fflag=1;
		if(n[i]==0){
			printf("N");
			continue;
		}
		switch(i){
			case 1: case 2: case 5 :case 3: printf("%d" , a[i]);break;
			case 4:printf("%.1f", float(a[4])/n[4]);break;
		}
	}
	//printf("%d %d %d %.1f %d\n",a[1],a[2],a[3],(float)a[4]/n,a[5]);
}
int main()
{
	sol();
	return 0;
}
//bsc_1012.cc
//generated automatically at Wed Nov  2 17:09:19 2016
//by xsthunder

//AC at Wed Nov  2 17:41:58 2016
 
