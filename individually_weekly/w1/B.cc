#include<cstdio>
#include<queue>
using namespace std;
const int D = 2000;
typedef long long ll;
void inp();
ll f1(int n,int m,int k,ll cnt);
ll f2(int n,int m,int k,ll cnt);
int main(){
	int T;
	scanf("%d" ,&T);
	for(int i =1;i<=T;i++){
		int n,m,k;
		scanf("%d%d%d", &n,&m,&k);
		printf("Case #%d: %lld %lld\n",i,f1(n,m,k,0),f2(n,m,k,0));
	}
	return 0;
}
ll f11(int x){
	return x-1;
	ll cnt = 0;
	if(x%2)cnt++;
	while(x!=1){
		cnt++;
		x/=2;
	}
	return cnt;
}
ll f1(const int n,const int m,const int k,ll nt){
	ll cnt =0 ;
	ll pcnt=1;
	if(n!=1){
		cnt+=f11(n);
		pcnt*=(f11(n)+1);
	}
	if(m!=1){
		cnt+=pcnt*f11(m);
		pcnt*=(f11(m)+1);
	}
	if(k!=1)cnt+=pcnt*f11(k);
	return cnt;
}
ll f22(int n){
	int cnt =0;
	if(n==1)return 0;
	if(n%2){
		cnt++;
		n--;
	}
	while(n!=1){
		cnt++;
		n/=2;
	}
	return cnt;
}
ll f2(int n,int m,int k,ll cnt){
	return f22(n)+f22(m)+f22(k);
}
