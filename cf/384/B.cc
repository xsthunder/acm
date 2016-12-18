const bool test=0;
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
int ans=-1;
ll lest;
ll tmp;
bool ask(ll k){
	tmp=1;
	lest=1;
	while(tmp<=k){
		if(tmp==k){
			return 1;
		}
		lest++;
		tmp<<=1;
		 IF cout<<"in ask "<<tmp<<' '<<lest<<endl;
	}
	lest--;
	tmp>>=1;
	return 0;
}
void sol(){
	ll n,k;
	cin>>n>>k;
	while(!ask(k)){
		IF cout<<tmp<<' '<<lest<<endl;
		k-=tmp;
	}
	cout<<lest<<endl;
}
int main()
{
	sol();
	return 0;
}
//B.cc
//generated automatically at Wed Dec 14 23:07:08 2016
//by xsthunder

