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
int G[600][600];
int dp[5][50];
int C[50][50];
int ans = 1e9;
int p[3];
int n,x,c;
void jd(){
	int cur = 0;
	for(int i = 0;i<3;i++){
		for(int j = 1;j<=c;j++){
			cur += dp[i][j] * C[ j ][ p[ i] ];
		}
	}
	ans = min(ans, cur);
}
void inp(){
	scanf("%d", &n); scanf("%d",&c);
	for(int i = 1;i<=c;i++){
		for(int j =1;j<=c;j++){
			scanf("%d", &C[i][j]); // from i to j
		}
	}
	for(int i =1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&G[i][j]);
			int r = (i+j)%3;
			dp[r][ G[i][j] ] ++;
		}
	}
	for(int i = 1;i<=c;i++){
		for(int j = 1;j<=c;j++){
			for(int k = 1;k<=c;k++){
				if( i == j || j == k || i == k)continue;
				p[0]=i;
				p[1]=j;
				p[2]=k;
				jd();
			}
		}
	}
	printf("%d", ans);
}
//d.cc by xsthunder at Fri Jul 27 23:58:32 2018

