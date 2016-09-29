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
const int N=2e5+10;
int A[N];
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif

	int T;
	SC(T);
	while(T--){
		int n,m,k;
		SC(n);SC(m);SC(k);
		MS(A);
		rep(i,0,n-1){
			int x;
			SC(x);
			if(x>=m)A[i]=1;
//cout<<A[i];
		}
//		cout<<endl;
		lld cnt=0;
		int sum=0;
		int r=-1;
		for(int i=0;i<=n-1;i++){
			while(r<n&&sum<k){
				r++;sum+=A[r];
			}
			if(sum<k)break;
			cnt+=n-1-r+1;
			sum-=A[i];
		}
		//	cout<<t<<' '<<e<<' '<<sum<<' '<<cnt<<endl;
		cout<<cnt<<endl;
		
	}
	
	//insert code
	return 0;
}
//bc86-c.cc

//AC

