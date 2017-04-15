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
char ans[][20]={"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten","eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
char keta[][20]={
	"","","twenty","thirty","forty","fifty"
};
void num(int n  ){
	if(n>20){
		int a , b;
		a=n/10;
		b=n%10;
		cout<<keta[a];
		cout<<' '<<ans[b];
	}
	else {
		cout<<ans[n];
	}
}
void sol(){
	int h,m;
	cin>>h>>m;
	if(m){
		num(h);
		cout<<' ';
		num(m);
	}
	else {//m==0
		num(h);
		cout<<' '<<"o'clock";
	}
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//67.cc
//generated automatically at Sat Feb  4 16:42:04 2017
//by xsthunder

