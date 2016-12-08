#include<cstdio>
const int maxn=1000;
int A[maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	A[0]=0;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		A[i]+=A[i-1]+x;
	}
	int ans=0;
	for(int i=0;i<m;i++){
		int r,l;
		scanf("%d%d",&l,&r);
		int sub=(A[r]-A[l-1]);
		//printf("sub %d,%d : %d\n",l,r,sub);
		if(sub>0)ans+=sub;
	}
	printf("%d\n", ans);
}
