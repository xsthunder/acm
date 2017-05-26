const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
#include<deque>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
ll c,k1,b1,k2;
const int C = 3e5;
int A[C] ;
void pre();
ll qpow(ll a,ll p){//requires c
	ll res= 1;
	ll curbase =a;
	while(p){
		if(p&1){
			res*=curbase;
		}
		curbase*=a;
		curbase%=c;
		res%=c;
		p>>=1;
	}
	return res;
}
const int n = 1e8;
bool sol(int a,int b){
	ll CA=qpow(a,k1);
	ll CB=qpow(b,k2);
	ll curA=(CA*qpow(a,b1))%c;
	ll curB=b;
	for(int i = 2;i<=n;i++){
		curA*=CA;
		curA%=c;
		curB*=CB;
		curB%=c;
		if(((curA+curB)%c)!=0)return 0;
		//cout<<i<<' '<<curA<<' '<<curB<<endl;
	}
	return 1;
}
void pre(){
	int k=0;
	while(scanf("%lld%lld%lld%lld",&c,&k1,&b1,&k2)!=EOF){
		int none=1;
		printf("Case #%d:\n",++k);
		for(int i = 1;i<c;i++){//for a
			A[i]=c-qpow(i,k1+b1);//store b
			if(A[i]==c)A[i]=0;
		}
		for(int i = 1;i< c;i++){
			if(A[i]&&sol(i,A[i])){
				none=0;
				printf("%d %d\n",i,A[i]);
			}
		}
		if(none)printf("-1\n");
	}
}
int main()
{
	pre();
	return 0;
}
//5478.cc
//generated automatically at Sun Mar 12 19:03:47 2017
//by xsthunder

