#include<cstdio>
#include<cstring>
typedef long long ll;
typedef ll M[4][4];
#define CP(x,y) memcpy(x,y,S)
#define MS(x) memset(x,0,S)
const int mod = 1e8+7;
const int N = 4;
const int S=sizeof(M); 
void qp(M,ll,M);
void pM(M a);
void MtM(M a,M b,M c){
	M ans;
	MS(ans);
	for(int i =0;i< N;i++){
		for(int j =0 ;j <N ;j++){
			for(int   k= 0 ;k<N;k++){
				ans[i][j]+=a[i][k]*b[k][j]%mod;
			}
			ans[i][j]%=mod;
		}
	}
	CP(c,ans);
}
int main(){
	ll n; 
	while(scanf("%lld\n", &n)!=EOF){
		if(n<=2)printf("%d\n", 1);
		else {
			M u = {
				1,1,1,0,
				1,0,0,0,
				0,0,1,1,
				0,0,0,1
			};
			M ansM={{0}};
			ll ans = 0;
			qp(u,n-2,ansM);
			//pM(ansM);
			ans+=(ansM[0][0]+ansM[0][1]+ansM[0][2]*3+ansM[0][3])%mod;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
void qp(M a,ll n,M c){
	M t;
	M ans;
	MS(ans);
	for(int i =0;i<N;i++){
		ans[i][i]=1;
	}
	CP(t,a);
	while(n){
		if(n&1)MtM(t,ans,ans);
		MtM(t,t,t);
		n>>=1;
	}
	CP(c,ans);
}
void pM(M a){
	for(int i =0;i< N;i++){
		for(int j =0;j< N;j++){
			printf("%5lld",a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
