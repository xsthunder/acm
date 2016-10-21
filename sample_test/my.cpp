const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<i<<' '<<*(begin+i);  printf("\n"); }}
char s[30];
double maxium;
int const N=1e6+10;
double p[N];
void pre(){
	int n=N-10;
	double ans=0;
	for(ll i=1;i<=n;i++){
		ans+=(double)1/(i*i);
		p[i]=ans;
//cout<<ans;
	}
	maxium=ans;
	//IF pA(p,68000);
}
int getnum(char *s){
	int len=strlen(s);
	int n=0;
	int base=1;
	for(int i=len-1;i>=0;i--){
		n+=(s[i]-'0')*base;
		base*=10;
	}
	return n;
}
void sol(){
	pre();
	while(scanf("%s",s)!=EOF){
		int len=strlen(s);
		if(len>=7)printf("%.5lf\n",maxium);
		else{
			double ans=0;
			int n=getnum(s);
	//		IF printf("%d:",n);
			ans=p[n];
			printf("%.5lf\n",ans);
		}
	}
}
int main()
{
	sol();
	return 0;
}
//0G.cc
//generated automatically at Fri Oct 21 02:16:51 2016
//by xsthunder

