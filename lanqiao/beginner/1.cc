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
	ll tmp;
	ll tmp2;
	cin>>tmp;
	tmp2=tmp+1;
	//cout<<tmp<<' '<<tmp2<<endl;
	if(tmp&1)tmp2/=2;
	else tmp/=2;
//	cout<<tmp<<' '<<tmp2<<endl;
	cout<<tmp*tmp2<<endl;
}
int main()
{
	sol();
	return 0;
}
//1.cc
//generated automatically at Sun Jan 15 21:56:42 2017
//by xsthunder

