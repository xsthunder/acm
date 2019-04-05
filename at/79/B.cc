#include<cstdio>
#include<iostream>

#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	try{
		//while(1)
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 50;
const ll A = 10000000000000000LL+1000LL;
void inp(){
	ll k;cin>>k;
	ll sum,cap;
	for(int i =2;i<=N;i++){
		for(int j = 0;j<(i-1)*i;j++){
			sum = k + j;
			if(sum%i != 0 )continue;
			cap = (sum + A -1 )/A;
			if(cap > i)continue;
			ll tar = sum/i;
			if(tar<i)continue;
			for(int k = 0;k<i;k++){
				if(k)cout<<' ';
				cout<<tar;
				return;
			}
		}
	}
}
//B.cc by xsthunder at Sat Jul 29 20:23:47 2017

