const bool TEST=0;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
#include<sstream>
#include<stack>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
int const N = 3000;
int a[N+1];
void mul(int fac){
	for(int i = N ; i>0 ;i--){
//		IF cout<<i<<endl;
		int ans=a[i]= a[i]*fac;
		IF {
			cout<<i<<' '<<ans<<endl;
//			if(i==N-3)break;
		}
	}
	for(int i =N ; i>  0 ;i--){
		int ans = a [ i] ;
		a[ i ]= ans%10;
		ans/=10;
		int cur = i -1;
		while(ans){
			a[cur]+=ans%10;
			cur--;
			ans/=10;
		}
	}
}
void sol(){
	a[N]=1;
	int n ;
	cin>>n;
	for(int i = 1; i <=n;i++){
		mul(i);
	}
	int b = 0 ;
	while(!a[b]){
		b++;
	}
	for(int i =b ; i<=N;i++){
		printf("%d", a[i]);
	}
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//71.cc
//generated automatically at Wed Feb  8 10:38:17 2017
//by xsthunder

