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
char as[2][20]{
	"What a pity!",
		"Wonderful!" };
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n,m;
	while(scanf("%d%d", &n,&m)==2&&(n||m)){
		int sum=0;
		sum+=n+m-2;
		int ans=0;
		ans=sum%(2+1)>0?1:0;
		cout<<as[ans]<<endl;
	}

	
	//insert code
	return 0;
}
//hdu2147.cc

