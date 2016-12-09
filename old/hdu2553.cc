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
int n,tol;
int vis[3][100];
void defs(int cur){
	if(cur==n)tol++;
	else{
		rep(i,0,n-1){
			if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+n]){
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=1;
				defs(cur+1);
				vis[0][i]=vis[1][cur+i]=vis[2][cur-i+n]=0;
			}
		}
	}

}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int a[20];
	rep(i,0,10){
		MS(vis);
		n=i;
		tol=0;
		defs(0);
		a[i]=tol;

	}

	while(SC(n)!=EOF&&n){
		printf("%d\n", a[n]);
	}
	//insert code
	return 0;
}
//hdu2553.cc

