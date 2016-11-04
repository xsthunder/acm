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
const int N=1e6+10;
int is_prime[N];
int prime[N];
void sol(){
	int m,n;
	scanf("%d%d",&m,&n);
	int cnt=0;
	for(int i=2;i<=N;i++){
		if(is_prime[i]==0)prime[cnt++]=i;
		for(int j=2;(ll)i*j<=N;j++){
			is_prime[i*j]=1;
		}
	}
//	cout<<cnt;
//	return ;
	int i=m-1;
	while(i<n){
		bool fflag=0;
		for(int j=0;j<10;j++){
			if(fflag)printf(" ");
			fflag=1;
			printf("%d", prime[i]);
			i++;
			if(i<n);
			else break;
		}
		printf("\n");
	}
}
int main()
{
	sol();
	return 0;
}
//bsc_1013.cc
//generated automatically at Fri Nov  4 16:12:48 2016
//by xsthunder

//AC at Fri Nov  4 16:26:29 2016
 
