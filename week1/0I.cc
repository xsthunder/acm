const bool test=0;
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
#define MS(s) memset((s),0,sizeof((s)))
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
const int N=300+50;
ll ak[N];
ll av[N];
ll sum[N];
ll dp[N][N];
void sol(){
	int TK;scanf("%d",&TK);
	while(TK--){
		MS(ak);MS(av);MS(dp);MS(sum);
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&ak[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&av[i]);
			sum[i]=sum[i-1]+av[i];
		}
		int j;
		for(int len=2;len<=n;len++){
			for(int i=1;i+len-1<=n;i++){
				j=i+len-1;
				if(__gcd(ak[i],ak[j])!=1&&dp[i+1][j-1]==sum[j-1]-sum[i]){
(dp[i][j]=sum[j]-sum[i-1]);
					continue;
				}
				else {
					for(int k=i;k<j;k++){
						dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
						//(dp[i][j]=sum[j]-sum[i-1]);
					}
				}
			}
		}
		IF {
			cout<<TK<<endl;
			for(int i=1;i<=n;i++)cout<<i<<' ';
			for(int i=1;i<=n;i++){cout<<i<<':';
				for(int j=1;j<n;j++)cout<<dp[i][j];
			}
			cout<<endl;
		}
		printf("%lld\n",dp[1][n]);
	}
}
int main()
{
	sol();
	return 0;
}
//0I.cc
//generated automatically at Fri Oct 21 05:40:49 2016
//by xsthunder

