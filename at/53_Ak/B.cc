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
const int N= 2e5+1e5;
char s[N];
void sol(){
	scanf("%s", s);
	int len = strlen(s);
	int _max=0;
	int _min = len-1 ;
	for(int i= 0;i<len;i++){
		switch(s[i]){
			case 'A':_min=min(_min,i);
							 break;
			case 'Z':_max=max(_max,i);
							 break;
			default:break;
		}
	}
	cout<<_max-_min+1<<endl;
}
int main()
{
	sol();
	return 0;
}
//B.cc
//generated automatically at Sat Jan 28 20:10:52 2017
//by xsthunder

