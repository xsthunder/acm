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
	int a,b,c;
	cin>>a>>b>>c;
	int ans=min(a,min(b/2,c/4));
	cout<<ans*7<<endl;
}
int main()
{
	sol();
	return 0;
}
//A.cc
//generated automatically at Sun Dec 18 18:37:02 2016
//by xsthunder

