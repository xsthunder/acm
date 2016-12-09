#include<iostream>
#include<cctype>
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
#include<cmath>
const int inf=0x7fffffff;
typedef long long int ll;
using namespace std;
int n;
const int N=1000;
bool A[N+10];
void solve(){
	memset(A,0,sizeof(A));
	A[0]=0;
	for(int i=1;i<=n;i++){
		A[i]=0;
		for(int j=1;j<=i;j*=2){
			A[i]|=!A[i-j];
		}
	}
	puts(A[n]?"Kiki":"Cici");
}
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	while(scanf("%d", &n)!=EOF){
		solve();
	}
	//insert code above
	return 0;
}
//hdu1847.cc
//generated automatically at Fri Sep  2 14:13:13 2016
//by xsthunder

//AC

