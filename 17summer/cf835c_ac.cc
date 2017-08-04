#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("cf835c.in","r",stdin);
#endif
	//while(1)
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int D = 105;
int n,q,c;
const int X=0,Y=1,S=2,N=1e5+100,C = 12;
int st[N][3],sum[C][D][D];
void pre(){
	int i,j,k,sc,x,y;
	for(i = 0;i<c;i++){
		for(j = 0;j<n;j++){
			sc = (st[j][S]+i)%c;
			x = st[j][X],y=st[j][Y];
			sum[i][y][x]+=sc;
		}
		for(j = 0;j<D;j++){
			for(k = 1;k<D;k++){
				sum[i][j][k]+=sum[i][j][k-1];
			}
		}
	}
}
void inp(){
	scanf("%d%d%d",&n,&q,&c);c++;
	int i;MS(st,0);MS(sum,0);
	for(i = 0;i<n;i++){
		scanf("%d%d%d", &st[i][X],&st[i][Y],&st[i][S]);
	}
	pre();//sum[][][]
	int t,x1,y1,x2,y2,ans,j;
	for(i = 0;i<q;i++){
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		ans = 0;t%=c;
		for(j = y1;j<=y2;j++){
			ans+= sum[t][j][x2] - sum[t][j][x1-1];
		}
		printf("%d\n",ans);
	}
}
//cf835c.cc by xsthunder at Thu Aug  3 09:17:02 2017

//AC at Fri Aug  4 08:46:21 2017
 
