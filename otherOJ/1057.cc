#include<cstdio>
const int MOD = 10007;
const int DE= 0;
void init();
int f[30];
int main(){
	int T;
	int n;
	int ans ;
	int x;
	init();
//	return 0 ;
	scanf("%d", &T);
	while(T--){
		ans=1;
		scanf("%d",&n);
		for(int i = 0 ;i< n-1;i++){
			scanf("%d", &x);
			ans*=f[x];
			ans%=MOD;
		}
		printf("%d\n", ans);
	}
}
void init(){
	f[2]=2;
	f[1]=1;
	f[0]=1;
	for(int i = 3 ;i<21;i++){
		f[i]=f[i-1]+f[i-2]+f[i-3];
		if(DE)printf("%d : %d\n", i,f[i]);
	}
}
