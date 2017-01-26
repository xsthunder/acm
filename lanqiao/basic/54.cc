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

	int n;
	scanf("%d",&n);
	int a,b,c;
	c=n%60;
	n/=60;
	b=n%60;
	a=n/60;
	char tmp[ 10];
	string ans;
	sprintf(tmp,"%d", a);
	ans+=tmp;
	ans+=':';
	sprintf(tmp,"%d", b);
	ans+=tmp;
	ans+=':';
	sprintf(tmp,"%d", c);
	ans+=tmp;
	cout<<ans<<endl;
}
int main()
{
	sol();
	return 0;
}
//54.cc
//generated automatically at Tue Jan 17 14:59:49 2017
//by xsthunder

