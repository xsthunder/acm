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
	int T;
	SC(T);
	while(T--){
		int n,m;
		SC(n);SC(m);
		llu tmp=0;
		llu sum=0;
		while(n--){
			scanf("%llu", &tmp);
			sum+=tmp;
		}
		while(m--){
			scanf("%llu", &tmp);
			cout<<(tmp>sum?1:0);
		}
		cout<<endl;
	}

	
	//insert code
	return 0;
}
//bc86-a.cc

