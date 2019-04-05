#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
int n;
const int N = 1e5;
int opt[N],cnt;
int dp[N];
void pA(int *a, int c){
	for(int i =0;i<c;i++){
		printf("%d\n", a[i]);
	}
}
void pre(){
	int i;
	for(i=6;i<=n;i*=6){
		opt[cnt ++] = i;
	}
	for(i=9;i<=n;i*=9){
		opt[cnt ++] = i;
	}
	dp[0] = 0;
	sort(opt,opt + cnt);
	for(int i = 1;i<=n;i++){
		dp[i] = dp[i - 1] + 1;
		for(int j = 0;opt[j] <= i && j < cnt;j ++){
			dp[i] = min(dp[i], dp[i - opt[j] ] + 1);
		}
		//printf("%d\n", dp[i]);
	}
}
void inp(){
	scanf("%d",&n);
	pre();
	printf("%d", dp[n]);
}
//c.cc by xsthunder at Fri Jul 27 23:30:07 2018

