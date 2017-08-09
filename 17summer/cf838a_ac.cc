#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("cf838a.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
#ifdef XS
const int cn=50;
#else 
const int cn=5000;
#endif
int g[cn+1][cn+1];
char s[2500];
void inp(){
	int n,m;scanf("%d%d",&n,&m);
	int i,j,k;
	int K = max(n,m);
	for(i=1;i<=n;i++){
		scanf("%s",s);
		for(j=1,k=0;j<=m;j++,k++){
			g[i][j]=s[k]-'0';
		}
	}
	for(i=1;i<=cn;i++){
		for(j=1;j<=cn;j++){
			g[i][j]+=g[i][j-1];
		}
	}
	for(j=1;j<=cn;j++){
		for(i=1;i<=cn;i++){
			g[i][j]+=g[i-1][j];
		}
	}
	int N,M,cur,x;
	int mi = g[n][m];
	for(k=2;k<=K;k++){
		N=(n+k-1)/k*k,M=(m+k-1)/k*k;
		cur=0;
		for(i=1;i<=N;i+=k){
			for(j=1;j<=M;j+=k){
				x= g[i+k-1][j+k-1]-g[i-1][j+k-1]-g[i+k-1][j-1]+g[i-1][j-1];
				cur+=min(x,k*k-x);
				if(cur>mi)goto exit;
			}
		}
exit:
		if(cur<mi)mi=cur;
	}
	printf("%d\n",mi);
}
//cf838a.cc by xsthunder at Mon Aug  7 15:34:13 2017

//AC at Mon Aug  7 15:59:57 2017
 
