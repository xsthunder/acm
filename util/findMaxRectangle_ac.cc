#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<stack>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("findMaxRectangle.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int N = 2000;
int g[N][N];
int s[N];
int findMaxRectangle(int *a,int n){
	int cnt=0;
	a[n]=0; n++;
	int ma=0;
	for(int i = 0;i<n;i++){
		while(cnt&&a[s[cnt-1]]>a[i]){
			int cur=s[cnt-1];cnt--;
			int wid=cnt?(i-s[cnt-1]-1):i;
			ma=max(ma,(a[cur])*wid);
			//printf("in %d cur %d wid:%d,ea:%d\n",i,cur,wid,a[cur]*wid);
		}
		s[cnt]=i; cnt++;
	}
	return ma;
}
void inp(){
	int h,w,x;scanf("%d%d",&h,&w);
	for(int i =1;i<=h;i++){
		for(int j =1;j<=w;j++){ scanf("%d",&x);g[i][j]=!x; }
	}
	int ma=0;
	//int a[]={2,1,5,6,2,3},n=sizeof(a)/sizeof(int);
	//printf("%d\n",findMaxRectangle(a,n));
	for(int i = 1;i<=h;i++){
		for(int j =1;j<=w;j++){
			if(g[i-1][j]&&g[i][j])
				g[i][j]+=g[i-1][j];
		}
		ma=max(ma,findMaxRectangle(&g[i][1],w));
	}
	printf("%d\n",ma);
}
//findMaxRectangle.cc by xsthunder at Mon Aug 21 22:30:32 2017

//AC at Mon Aug 21 22:53:39 2017
 
