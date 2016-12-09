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
const int N=120+10;
int c1[N];
int c2[N];
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int n;
	while(SC(n)!=EOF){
		for(int i=0;i<=n;i++){
			c1[i]=1;
		}
		MS(c2);
		for(int i=2;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;j+k<=n;k+=i){
					c2[j+k]+=c1[j];
				}
			}
			for(int j=0;j<=n;j++){
				c1[j]=c2[j];
				c2[j]=0;
//				printf("%4d", c1[j]);
			}
//			cout<<endl;
		}
		cout<<c1[n]<<endl ;
	}

//注意都是小于等于n
	//insert code
	return 0;
}
//hdu1028.cc

