#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	if(n<=2)printf("1\n");
	n-=2;
	int f[3] = {1,1,1};
	for(int i =0 ;i<n;i++){
		f[0]=f[1];
		f[1]=f[2];
		f[2]=f[0]+f[1];
	}
	printf("%d\n", f[2]);
}
