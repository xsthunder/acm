#include<iostream>
#include<cmath>
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

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	SC(T);
	int x;
	while(T--){
		SC(x);
		int sum;
		double ans=0;
		rep(i,1,x){
			ans+=log10(i);
//			cout<<ans<<endl;
		}
		cout<<(int)floor(ans)+1<<endl
			;
	}

	
	//insert code
	return 0;
}
//hdu1018.cc

