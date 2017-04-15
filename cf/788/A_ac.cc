#include<cstdio>
#include<algorithm>
const int DE=0;
using namespace std;;
const int N= 1e5+100;
int n;
typedef long long int ll;
ll B[N];
ll A[N];
ll inp();
void deal();
int main(){
	printf("%lld\n",inp());
	//deal();
	return 0;
}
ll deal(ll* B){
	ll m =1L<<63; 
	ll sum  = 0 ;
	for(int i = 1 ;i< n;i++){
		if(DE)printf("B%ld " ,B[i]);
	//	if(DE)printf("A%ld " ,A[i]);
		sum+=B[i];
		if(sum < 0)sum = 0;
		m=max(sum , m );
		if(DE)printf("i: %d m : %ld\n" , i,m);
	}
	return m;
}
ll  inp(){
	scanf("%d", &n);
	for(int i =1;i<=n;i++){
		scanf("%lld", A+i);
	}
	int a  = 0;
	for(int i= 1;i<n;i++){
		B[i]=A[i+1]-A[i];
		B[i]=abs(B[i]);
		if(a)B[i]=-B[i];
		a=!a;
	}
	ll ans1 = deal(B);
	for(int i =1;i<n;i++){
		B[i]=-B[i];
	}
	ll ans2 = deal(B);
	return max(ans1,ans2);
}
//AC at Sun Apr  2 11:19:30 2017
 
