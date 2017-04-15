#include<cstdio>
int main(){
	int T,a,b,c;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d%d", &a,&b,&c);
		printf("%d\n", -(c/4-b-a/2));
	}
	return 0;
}
