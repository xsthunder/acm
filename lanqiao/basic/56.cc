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

	string s1,s2;
	cin>>s1>>s2;
	int ans=-1;
	if(s1.size()==s2.size()){
		if(s1==s2)ans=2;
		else {
			for(U i = 0 ; i<s1.size();i++){
				if(tolower(s1[i])==tolower(s2[i])){
					if(i==s1.size()-1)ans=3;
				}
				else {
					ans=4;
					break;
				}
			}
		}
	}
	else ans=1;
	cout<<ans<<endl;
}
int main()
{
	sol();
	return 0;
}
//56.cc
//generated automatically at Tue Jan 17 15:05:24 2017
//by xsthunder

