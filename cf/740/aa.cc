#include<cstdio>
typedef long long int ll;
ll min(ll a,ll b){
	if(a<b)return a;
	else return b;
}
int main(){
	ll P[4];
	ll ans=0x7ffffffffffffff;
	int mod=4;
	for(int i=0;i<4;i++){
		scanf("%lld", &P[i]);
	}
	ll n = P[0];
	for(int i1=0;i1<4;i1++){
		for(int i2=0;i2<4;i2++){
			for(int i3=0;i3<4;i3++){
				if((n+i1+i2*2+i3*3)%mod==0){
					ans=min(ans,i1*P[1]+i2*P[2]+i3*P[3]);
//					printf("%d %d %d %lld\n",i1,i2,i3,ans);
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
