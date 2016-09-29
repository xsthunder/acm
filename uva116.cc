
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
using namespace std;
const int inf=0x7fffffff;
typedef long long int lld;
int n,m;
const int N=100+5;
const int M=10+5;
int b[M][N];
int d[M][N];
int a[M][N];
int p[M][N];
int cnv(int x){
    if(x==0)return m;
    else if(x==m+1)return 1;
    else return x;
}
lld solve(int x,int y){
	if(x>m||y>n||x<1||y<1)return 0;
	if(b[x][y])return d[x][y];
	int j=y+1;
	lld temp;
	lld best=(lld)1<<62;
	for(int l=x-1;l<=x+1;l++){
		int i=cnv(l);
		temp=solve(i,j)+a[x][y];
		if(best>temp){
			best=temp;
			p[x][y]=i;

		}
		else if(best==temp){
			if(i<p[x][y]){
				best=temp;
				p[x][y]=i;

			}
		}

	}
//	for(int i=1;i<=10;i++)printf("%3d",i);cout<<endl;
//	for(int i=1;i<=m;i++){for(int j=1;j<=n;j++){;printf("%3d", d[i][j]);}cout<<endl;};
//	printf("                                                                          \n");
//	for(int i=1;i<=m;i++){for(int j=1;j<=n;j++){;printf("%3d", b[i][j]);}cout<<endl;};
//		printf("                                                                          \n");
//	for(int i=1;i<=m;i++){for(int j=1;j<=n;j++){;printf("%3d", p[i][j]);}cout<<endl;};
//		printf("                                                                          \n");
	b[x][y]=1;
	return d[x][y]=best;
}
int main()
{
#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(scanf("%d%d", &m,&n)!=EOF){
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				scanf("%d", &a[i][j]);
			}
		}
		for(int j=n, i=1;i<=m;i++){d[i][j]=a[i][j];b[i][j]=1;}
		lld best=((lld)1<<62);
		int j=1;
		int besti=-1;
		lld temp;
		for(int i=1;i<=m;i++)
		{
			temp=solve(i,j)	;
			if(best>temp){
				besti=i;
				best=temp;
			}
			else if(best==temp){
				if(a[besti][j]>a[j][i]){
					besti=i;
					best=temp;
				}
			}
		}
		printf("%d", besti);

		for(int i=1;i<n;i++){
			printf(" %d",besti=p[besti][i]);
		}

//			for(int i=1;i<=m;i++){for(int j=1;j<=n;j++){;printf("%3d", d[i][j]);}cout<<endl;};
//	printf("                                                                          \n");
//	for(int i=1;i<=m;i++){for(int j=1;j<=n;j++){;printf("%3d", b[i][j]);}cout<<endl;};
//		printf("                                                                          \n");
//	for(int i=1;i<=m;i++){for(int j=1;j<=n;j++){;printf("%3d", p[i][j]);}cout<<endl;};
//		printf("                                                                          \n");
		printf("\n%lld\n",best);
	}
	//insert code
	return 0;
}
//uva116.cc

