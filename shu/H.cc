#include<cstdio>
#include<cstring>
#define MS(c) memset(c,0,sizeof(c))
const int N=200;
int A[N];
int B[N];
int n;
int dea();
void sol();
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		sol();
	}
	return 0;
}
void sol(){
	scanf("%d", &n);
	MS(A);MS(B);
	int x;
	for(int i =0 ;i< n;i++){
		scanf("%d", &x);
		A[x]++;
	}
	for(int i =0 ;i< n;i++){
		scanf("%d", &x);
		B[x]++;
	}
	printf("%d\n",dea());
}
int dea(){
	int cnt=0;
	int val=0;
	int b=0;
	for(int i=1;i<=5;i++){
		int x=A[i];
		int y=B[i];
		if((x+y)%2)return -1;
		val = x-y;
		if(val> 0)cnt+=val;
		b+=val;
	}
	if(b)return -1;
	else return cnt/2;
}
