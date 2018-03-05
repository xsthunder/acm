#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
int exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int gcd = exgcd(b,a%b,x,y);
	int tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return gcd;
}
//return a^(-1) (mod b)
ll Inv(ll a,ll b)  
{  
    ll x,y,c=1;  
    ll gcd=exgcd(a,b,x,y);  
    if(c%gcd!=0) return -1;  
    x*=c/gcd;  
//    b/=gcd;  
    if(b<0) b=-b;  
    ll ans=x%b;  
    if(ans<=0) ans+=b;  
    return ans;  
}  
void inp(){
	ll a,p;
	scanf("%lld%lld", &a,&p);
	ll ans = Inv(a,p);
	if(ans == -1)puts("Not Exist");
	else printf("%lld\n",ans);
}
//zoj3609.cc by xsthunder at Mon Nov  6 21:45:30 2017

