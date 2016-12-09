#include<cstdio>
#include<iostream>
using namespace std;
const int N=1e5+100;
int Cnt[N*10];
int B[N*10];
void pA(int *arr,int n){
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main(){
	int x;
	int n;
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++){
		int tmp;
		scanf("%d", &tmp);
		Cnt[tmp]++;
		B[tmp^x]++;
		//printf("%d^%d : %d \n", tmp,x,tmp^x);
	}
	long long ans=0;
	for(int i=0;i<N;i++){
		if(x==0){
			ans+=Cnt[i]*(Cnt[i]-1);
		}
		else 
		{
			ans+=Cnt[i];
		}
	}
	//pA(Cnt,3);
	//pA(B,3);
	ans/=2;
	cout<<ans<<endl;
	return 0;
}
