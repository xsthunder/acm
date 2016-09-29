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
char as[][10]={
	"second",
	"first"
};
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
		int ans;
		if(n%(m+1)>0){
				ans=1;
			}
		else ans=0;
		cout<<as[ans]<<endl;
	}

	
	//insert code
	return 0;
}
//hdu1846.cc

