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

const int N=1e3+10;
int W[N];
int V[N];
int D[N];
int n,v;
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	SC(T);
	while(T--){
		MS(D);MS(W);MS(V);
		SC(n);SC(v);
		rep(i,0,n-1){
			SC(V[i]);
		}
		rep(i,0,n-1){
			SC(W[i]);
		}
//		rep(j,0,n-1){
//			printf("%4d",W[j]);
//		}
//j		rep(j,0,v)printf("%4d", j);
//j		cout<<endl;
//		cout<<n;
		rep(i,0,n-1){
			per(j,v,0){
				if(j>=W[i])D[j]=max(D[j],D[j-W[i]]+ V[i]);
			}
//			rep(j,0,v){
//				printf("%4d",D[j]);
//			}
			//cout<<endl;
		}
	cout<<D[v]<<endl;
	}

	
	//insert code
	return 0;
}
//hdu2602.cc

//AC

