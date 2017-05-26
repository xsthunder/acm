#include<cstdio>
int main(){
	int T;
	scanf("%d", &T);
	int a,b,c;
	long long int A,C;
	long long int sum;
	while(T--){
		sum=0;
		scanf("%d%d%d", &a,&b,&c);
		sum+=a*b;
		A=a/10;
		C=A/3;
		sum+=C*c;
		printf("%lld\n", sum);
	}

	return 0;
}
