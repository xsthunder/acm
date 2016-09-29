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
const int N=1e5+10;
int A[N];
int F[N];
int B[N];
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	SC(T);
	while(T--){
		int n;
		SC(n);
		MS(B);MS(F);
		rep(i,1,n){
			SC(A[i]);
		}
		rep(i,1,n-1){
			F[i+1]=max(F[i],abs(A[i]-A[i+1]));
		}
		per(i,n-1,1){
			B[i]=max(B[i+1],abs(A[i]-A[i+1]));
		}
		lld sum=0;
		sum+=B[2];
		sum+=F[n-1];
		rep(i,2,n-1){
			int best=0;
			best =max(B[i+1],F[i-1]);
			best=max(best,abs(A[i-1]-A[i+1]));
			sum+=best;
//			cout<<i<<' '<<best<<endl;
		}
		cout<<sum<<endl;
//		cout<<'i';
//		rep(i,1,n)printf("%4d",i);
//		cout<<endl;
//		cout<<'F';
//		rep(i,1,n)printf("%4d",F[i]);
//		cout<<endl;
//		cout<<'B';
//		rep(i,1,n)printf("%4d", B[i]);
//		cout<<endl;

	}

	
	//insert code
	return 0;
}
//bc86-b.cc

