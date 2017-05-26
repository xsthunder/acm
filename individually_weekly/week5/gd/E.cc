#include<cstdio>
bool isp(int a){
	int mask=1;
	for(int i= 0 ;i < 10;i++){
		if(!(a^mask))return 1;
		mask<<=1;
	}
	return 0;
}
const int MAX=2e9;
int main(){
	int T;
	scanf("%d", &T);
	int N,K;
	int A=0;
	int B=0;
	 int max=MAX;
	while(T--){
		A=0,B=0;
		max=MAX;
		scanf("%d%d", &N,&K);
		for(int i = 1;i<=K;i++){
			if(isp(i)){
				A=N/i;
				B=A-N%i;
				if(B<max)max=B;
			}
		}
		printf("%d\n",max);
	}

}
