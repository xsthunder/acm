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
const int N =1e5+10;
bool is_prime[N];//1 for not prime;
int prime[N];
int cnt=0;
void pri(){
	prime[cnt++]=-1;
	for(int i=2;i<N;i++){
		if(is_prime[i]==0){
			prime[cnt++]=i;
			for(int j=2;i*j<N;j++){
				is_prime[i*j]=1;
			}
		}
	}
}
void sol(){
	int n;
	scanf("%d",&n);
	int ans=0;
	for(int i=1;prime[i]<=n;i++){
		if(prime[i]-prime[i-1]==2)ans++;
	}
	printf("%d\n",ans);
}
int main()
{
	pri();
	sol();
	return 0;
}
//bsc_1007.cc
//generated automatically at Tue Nov  1 19:49:04 2016
//by xsthunder

//AC at Tue Nov  1 20:01:14 2016
 
