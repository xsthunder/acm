#include<cstdio>
#include<cstring>
int main(){
	int T;
	scanf("%d", &T);
	unsigned int n,k;
	const int t=0;
	while(T--){
		scanf("%u%u",&n,&k);
		unsigned int mask=1<<31;;
		if(t)printf("%x %x\n",mask,n);
		for(unsigned int i = 0;i<k;i++){
			while(!(mask&n))mask>>=1;
			n-=mask;
			if(!n){
				mask=0,k=0;
			}
			if(t)printf("%x %x\n",mask,n);
		}
		printf("%d\n",mask-n);
	}
	return 0;
}
