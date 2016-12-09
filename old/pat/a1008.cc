#include<cstdio>
const int UP=6,DOWN=4,KEEP=5;
int main(){
	int n;
	scanf("%d",&n);
	int pre=0;
	int sum=0;
	while(n--){
		int nxt;
		scanf("%d", &nxt);
		if(nxt>pre)sum+=(nxt-pre)*UP+KEEP;
		else {
			sum+=(pre-nxt)*DOWN +KEEP;
		}
		pre=nxt;
	}
	printf("%d\n",sum);
}
//AC at Mon Nov 28 15:44:59 2016
 
