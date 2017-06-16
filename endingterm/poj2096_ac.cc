#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
double dp[2000][2000];
#define p2 (n-i)*(s-j)
#define p3 (i)*(s-j)
#define p4 (n-i)*j
#define div (ns-i*j)
void inp(){
	int n,s;
	cin>>n>>s;
	int ns=n*s;
	for(int i =n;i>=0;i--){
		for(int j =s;j>=0;j--){
			if(n==i&&s==j)continue;
			dp[i][j]=(
					ns
					+p2*dp[i+1][j+1]
					+p3*dp[i][j+1]
					+p4*dp[i+1][j]
					)/div;
		}
	}
	cout<<setiosflags(ios::fixed)<<setprecision(4)<<dp[0][0]<<endl;;
}
//poj2096.cc by xsthunder at Fri Jun 16 08:58:45 2017

//AC at Fri Jun 16 09:35:39 2017
 
