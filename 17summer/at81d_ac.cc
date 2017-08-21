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
	freopen("at81d.in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
int cnt=0;
int a[100];
char s[100];
char s2[100];
ll ans=0;
ll mod=1000000007;
void inp(){
	int n;scanf("%d",&n);
	scanf("%s%s",s,s2);
	if(n==1){ puts("3"); return ; }
	int i;
	for(i=0 ;i<n;i++){
		if(s[i]==s2[i]){ a[cnt++]=1; }
		else {a[cnt++]=2; i++; }
	}
	ll ans;
	if(a[0]==1)ans=3;
	else ans=6;
	ll t=0;
	for(i = 1;i<cnt;i++){
		if(a[i]==1){
			if(a[i-1]==1){ t=2; }
			else { t=1; }
		}
		else {
			if(a[i-1]==1){ t=2; }
			else { t=3; }
		}
		ans*=t;
		if(ans>=mod)ans-=mod;
	}
	printf("%lld\n",ans);
}
//at81d.cc by xsthunder at Sun Aug 20 20:19:34 2017

//AC at Sun Aug 20 20:48:12 2017
 
