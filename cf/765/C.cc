const bool TEST=1;
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
void sol(){
	int k,a,b;
	cin>>k>>a>>b; 
	ULL ans=0;
	ans+=a/k;
	ans+=b/k;
	if(a%k>0&&b/k==0){
		ans=0;
	}
	if(b%k>0&&a/k==0){
		ans=0;
	}
	if(ans==0){
		cout<<-1<<endl;
		return ;
	}
	cout<<ans<<endl;
}
int main()
{
	sol();
	return 0;
}
//C.cc
//generated automatically at Tue Feb 14 16:58:30 2017
//by xsthunder

