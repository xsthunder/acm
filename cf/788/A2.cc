#include<cstdio>
int main(){
	int n,k;
	scanf("%d%d", &n,&k);
	int w;
	int ans=0;
	while(n--){
		scanf("%d",&w);
		ans+=w/k;
		if(w%k)ans++;
	}
	printf("%d\n",ans/2+ans%2);
}
