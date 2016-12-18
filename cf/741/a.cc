#include<cstdio>
using namespace std;
typedef long long int ll;
ll ans=-1;
int D[200];
ll gcd(ll a,ll b){
	if(b==0)return a;
	else return gcd(b,a%b);
}
void cal(ll x){
	if(x%2==0)x/=2;
//	printf("in cal %lld %lld\n", ans,x);
	if(ans==-1)ans=1;
	ans=ans/gcd(x,ans)*x;
}
void sea(int &len,const int i,int nxt){
	len++;
//	printf("%d %d %d in sea\n",len,i,nxt);
	if(i==nxt||len>150){
		return ;
	}
	else {
		sea(len,i,D[nxt]);
	}
}
int main(){
	int n;
	if(0){
		int a,b;
		while(1){
			scanf("%d%d",&a,&b);
			//printf("%lld",gcd(a,b));
		}
		return 0;
	}
	scanf("%d",& n);
	for(int i=1;i<=n;i++){
		scanf("%d",&D[i]);
	}
	for(int i=1;i<=n;i++){
		int len=0;
		(sea(len,i,D[i]));
		//printf("%d %d %d in for i in n\n",len,i,D[i]);
		if(len<=150)
			cal(len);
		else {
			ans=-1;
			break;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
