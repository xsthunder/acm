#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	freopen("cf834c.in","r",stdin);
#endif
	//while(1)
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
char ans[][20]={
	"Yes","No"
};
void get(ll &d,ll c){
	ll l = 1,r = 1e6,m,tmp;
	d=0;
	while(l<=r){
		m = (l+r)/2;
		tmp=m*m*m;
		if(tmp>c){
			r = m-1;
		}
		else if(tmp<c){
			l = m+1;
		}
		else {
			d = m;
			break;
		}
	}
}
void inp(){
	int n;scanf("%d",&n);
	ll a,b,c,e;
	int flag = 1;
	for(int i = 0;i<n;i++){
		flag =1;
		scanf("%lld%lld",&a,&b);
		c = a*b;
		get(e,c);
		if(!e)flag = 0;
		else {
			//printf("%lld",e);
			if(a<e||b<e)flag =0;
			if(a%e!=0||b%e!=0)flag=0;
		}
		printf("%s\n",ans[!flag]);
	}
}
//cf834c.cc by xsthunder at Fri Aug  4 14:28:58 2017

//AC at Fri Aug  4 15:08:40 2017
 
