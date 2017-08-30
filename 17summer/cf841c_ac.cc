#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<queue>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
const int N = 2e5+100;
int A[N];
P B[N];
int ans[N];
void inp(){
	int n;
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%d",&A[i]);
	}
	for(int i =0;i<n;i++){
		scanf("%d",&B[i].first);B[i].second=i;
	}
	sort(A,A+n,greater<int>()),sort(B,B+n);
	for(int i=0;i<n;i++){
		ans[B[i].second]=A[i];
	}
	for(int i = 0;i<n;i++){
		if(i)putchar(' ');
		printf("%d",ans[i]);
	}
	putchar('\n');
}
//cf841c.cc by xsthunder at Tue Aug 29 09:41:16 2017

//AC at Tue Aug 29 10:09:42 2017
 
