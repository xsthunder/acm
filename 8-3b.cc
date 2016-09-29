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
#include<cmath>
using namespace std;
#define MS(x) memset(x, 0 ,sizeof(x)) 
#define SC(x) scanf("%d", & (x) )
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int inf=0x7fffffff;
typedef long long int lld;
typedef long long unsigned llu;
typedef long double lf;
const int N=1e5+100;
int A[N];
int B[N];
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	SC(n);
	lf sum;
	lf a,b;
	MS(A);MS(B);
	rep(i,0,n-1){
		cin>>A[i];
	}
	rep(i,0,n-1){
		cin>>B[i];
	}
	rep(i,0,n-1){
		a=A[i];
		if(a==0){sum=0;break;};
		b=B[i];
		sum+=b*log10(a);
//		cout<<a<<' '<<b<<' '<<sum<<endl;
	}
	if(sum==0)cout<<0<<endl;
	else cout<<(long long )floor(sum)+1<<endl;

	
	//insert code
	return 0;
}
//8-3b.cc

