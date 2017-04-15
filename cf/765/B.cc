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
	char x ;
	char cur='a'-1;
	while(scanf("%c",&x)!=EOF){
		if(x<=cur){

		}
		else {
			if(x==cur+1){
				cur=x;
			}
			else {
				cout<<"NO"<<endl;
				exit(0);
			}
		}
	}
	cout<<"YES"<<endl;
}
int main()
{
	sol();
	return 0;
}
//B.cc
//generated automatically at Tue Feb 14 16:51:07 2017
//by xsthunder

