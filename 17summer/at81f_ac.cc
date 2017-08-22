#include<cstdio>
#include<string>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("at81e.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
int ans;
const int N=3e5;
char s[N];
int fd[N][30];
int cnt=0;
const int D = 26;
int dp[N];
const int inf = 0x7fffffff;
void inp(){
	MS(fd,-1);
	scanf("%s",s);
	int len = strlen(s);
	for(int i =0;i<len;i++){ s[i]-='a'; }
	for(int i =len-1;i>=0;i--){ fd[i+1][(int)s[i]]=i+1; }
	for(int i =len;i>1;i--){
		for(int c=0;c<D;c++){
			if(fd[i][c]!=-1){
				if(fd[i-1][c]==-1)fd[i-1][c]=fd[i][c];
			}
		}
	}
	for(int i =0;i<N;i++){
		for(int j=0;j<D;j++)if(fd[i][j]==-1)
			fd[i][j]=N-1;
	}
	fill(dp,dp+len+1,inf);
	fill(dp+len+1,dp+N,0);
	for(int i =len;i>=0;i--){
		for(int j=0;j<D;j++){
			if(dp[i]>dp[fd[i+1][j]]+1){
				dp[i]=dp[fd[i+1][j]]+1;
			}
		}
	}
	for(int i =0;i<len;){
		for(int j =0;j<D;j++){
			if(dp[i]==dp[fd[i+1][j]]+1){
				putchar('a'+j);
				i=fd[i+1][j];
				break;
			}
		}
	}
	putchar('\n');
}
//at81e.cc by xsthunder at Sun Aug 20 20:48:17 2017

//AC at Mon Aug 21 09:08:20 2017
 
