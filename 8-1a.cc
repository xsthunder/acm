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

int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int x;
	int T,n;
	int ans=0;
	SC(T);
	while(T--){
		SC(n);
		SC(ans);
		cout<<ans<<endl;
		rep(i,0,n-2){
			SC(x);
			ans^=x;
			cout<<ans<<endl;
		}
	}

	
	//insert code
	return 0;
}
//8-1a.cc

//AC

