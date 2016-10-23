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
int Cnt(int n){
	int cnt=0;
	while(n!=1){
		if(n%2==0){
			n/=2;
		}
		else {
			n=3*n+1;
			n/=2;
		}
		cnt++;
	}
	return cnt;
}
void sol(){
	int n;scanf("%d",&n);
	printf("%d\n",Cnt(n));
}
int main()
{
	sol();
	return 0;
}
//bsc_1001.cc
//generated automatically at Sat Oct 22 11:22:45 2016
//by xsthunder

