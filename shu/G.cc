#include<cstdio>
#include<cstring>
#define MS(s) memset(s,0,sizeof(s))
const int N = 20;
double A[N];
int s[N];
int n;
void sol();;
int cou();
double dea(int x );
int main(){
	while(scanf("%d", &n)!=EOF){
		MS(s);
		MS(A);
		sol();
	}
	return 0;
}
void sol(){
	for(int i=0;i< n;i++){
		scanf("%lf",&A[i]);
	}
	double res=0;
	for(int i =0 ;i< 1<<n;i++){
		res+=dea(i);
	}
	printf("%lf\n", res);
}
const int test=0;
#define IF if(test)
int cou(){
	int cnt=0;
	int res=0;
	s[n]=0;
	for(int i=0;i<=n;i++){
		IF printf("%d",s[i]); 
		if(s[i])cnt++;
		else {
			res+=cnt*cnt;
			cnt=0;
		}
	}
	IF printf(":%d\n",res);
	return res;
}
double dea(int x ){
	double p =1;
	MS(s);
	for(int i=0;i<n;i++){
		if(x&1){
			s[i]=1;
			p*=A[i];
		}
		else {
			s[i]=0;
			p*=1-A[i];
		}
		x>>=1;
	}
	IF printf("in dea : %lf,cou:%d\n",p,cou());
	return p*cou();
}
