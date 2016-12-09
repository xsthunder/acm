#include<cstdio>
int ans[6]={
	0,
	8,
	4,
	2,
	6,
	8,};

int sol(int n){
	if(n==0)return 1;
	int index=(n-1)%4+1;
	return  ans[index];
}
int main(){
	int n;
	scanf("%d",&n);
	printf("%d\n", sol(n));
	return 0;
}
