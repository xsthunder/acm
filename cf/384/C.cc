const bool test=1;
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
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
void sol(){
	ll n;
	cin>>n;
	if(n==1)cout<<-1<<endl;
	else cout<<n<<' '<<n+1<<' '<<n*(n+1)<<endl;
}
int main()
{
	sol();
	return 0;
}
//C.cc
//generated automatically at Wed Dec 14 23:50:24 2016
//by xsthunder

