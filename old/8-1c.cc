#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
using namespace std;
#define MS(x) memset(x, 0 ,sizeof(x)) 
#define SC(x) scanf("%d", & (x) )
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int inf=0x7fffffff;
typedef long long int lld;
typedef long long unsigned llu;
const int N=1200+10;
int a[N];
int p[N];
lld sum(int *a,int n){
	lld s=p[0];
	int ss=0;
	rep(i,0,n-1){
		s+=p[ss=ss+a[i]];
	}
	return s;
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	SC(T);
	T=1;
	while(T--){
		int n,t;
		MS(a);
		MS(p);
		SC(n);
		int card[4];
		rep(i,0,4-1){
			SC(card[i]);
		}
		t=0;
		rep(i,0,4-1){
			int x;
			SC(x);
			cout<<'|'<<i<<" ";
			for(int i=0;i<x;i++){
				cout<<t;
				a[t++]=card[i];
			}
		}
		rep(i,0,n-1){
			SC(p[i]);
		}
		lld best=0;;
		sort(a,a+t);
		cout<<t<<endl;
		do{
			best=max(sum(a,t),best);
		rep(i,0,t-1)cout<<i<<' '<<a[i]<<" "<<endl;
		}while(next_permutation(a,a+t));
		printf("%lld", best);
	}

	
	//insert code
	return 0;
}
//8-1c.cc

