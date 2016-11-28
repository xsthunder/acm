#include<cstdio>
int min(int a,int b){
	if(a<b)return a;
	else return b;
}
const int K=1e4+10;
const int inf=0x7ffffff;
void pA(int *b,int n){
	for(int i=0;i<n;i++){
		printf(" %3d",*(b+i));
	}
	printf("\n");
}

int D[K];
int S[K];
int F[K];
int main(){
	int k;
	scanf("%d",&k);
	bool zero=1;
	F[0]=D[0]=S[0]=0;
	for(int i=1;i<=k;i++){
		int x;
		scanf("%d",&x);
		if(x>=0)zero=0;
		S[i]=S[i-1]+x;
		D[i]=x;
		F[i]=(S[i]<S[F[i-1]]?i:F[i-1]);
	}
//	pA(S,k);
//	pA(D,k);
//	pA(F,k);
	int sum;
	int b,e;
	if(zero){
		//printf("zero==1\n");
		b=0;
		e=k;
		sum=0;
	}
	else {
		sum=-1;
		for(int i=1;i<=k;i++){
			if(sum<S[i]-S[F[i-1]]){
				sum=S[i]-S[F[i-1]];
				e=i;
				b=F[i-1];
			}
		}
	}
	printf("%d %d %d\n",sum,D[b+1],D[e]);
}
//AC at Mon Nov 28 10:28:41 2016
 
