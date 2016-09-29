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
	scanf("%d", &T);
	while(T--){
		int m,n;
		scanf("%d%d",&n,&m);
//		cout<<m<<n<<endl;
//		cout<<n%(m+1)<<endl;
		printf(n%(m+1)==0?"Rabbit\n":"Grass\n");
	}
	
	//insert code
	return 0;
}
//hdu2188.cc

//AC

