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
	string s ;
	while(n--){
		int x;
		scanf("%d",&x);
		s+=(x+'0');
	}
	int ask=0;
	scanf("%d",&ask);
	int pos= s.find_first_of(ask+'0');
	if(pos!=-1)pos++;
	cout<<pos<<endl;
}
int main()
{
	sol();
	return 0;
}
//9.cc
//generated automatically at Tue Jan 17 13:34:12 2017
//by xsthunder
