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
	//freopen(".in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
const int N = 2e3;
int A[N];
int D[N];
int cnt[N];
void inp(){
	int n;scanf("%d",&n);int x;
	for(int i =0;i<n;i++){
		scanf("%d",&x);
		A[i]=x;
	}
	if(n==1){
		puts("YES");
		return;
	}
	int i;
	for(i=1;i<n;i++){
		D[i]=A[i]-A[i-1];
	}
	int flag1=0,flag2=0,flag3=0;
	for(i=1;i<n;i++){
		if(!flag1&&D[i]>0)continue;
		else flag1=1;
		if(!flag2&&D[i]==0){
			flag1=1;
			continue;
		}
		else flag2=1;
		if(!flag3&&D[i]<0){
			flag1=flag2=1;
			continue;
		}
		else break;
	}
	if(i==n)puts("YES");
	else puts("NO");
		
}
//cf831a.cc by xsthunder at Sun Aug  6 08:26:38 2017

//AC at Sun Aug  6 08:49:03 2017
 
