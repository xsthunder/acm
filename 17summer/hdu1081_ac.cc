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
	freopen("hdu1081.in","r",stdin);
#endif
	while(1)inp();
	return 0;
}
int g[3000][3000];
void inp(){
	int n,x;if(scanf("%d",&n)==EOF)exit(0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){ scanf("%d",&x); g[i][j]=g[i-1][j]+x; }
	}
	ll ma=g[1][1];
	ll sum=0;
	for(int i=1;i<=n;i++){
		for(int k = 1;k<=i;k++){
			sum=0;
			for(int j=1;j<=n;j++){
				sum+=g[i][j]-g[k-1][j];
				if(sum<0)sum=0;
				if(sum>ma){
					ma=sum;
				//	printf("i:%d,j%d:,k%d: %lld\n",i,j,k,ma);
				}
			}
		}
	}
	printf("%lld\n",ma);
}
//hdu1081.cc by xsthunder at Tue Aug 22 08:11:38 2017

//AC at Tue Aug 22 08:28:10 2017
 
