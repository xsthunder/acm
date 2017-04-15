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
map<string ,int>msi;
int msicnt=0;
int getid(string s ){
	if(msi.count(s))return msi[s];
	else return msi[s]=msicnt++;
}
int a [ 200];
void sol(){
	string s ;
	int n;
	cin>>n>>s;
	int home = getid(s);
	while(n--){
		cin>>s;
		int f= getid(s.substr(0,3));
		int t=getid(s.substr(5));
		if(f==home){
			a[t]++;
		}
		else {//t==home
			a[f]--;
		}
	}
	for(int i =0 ;i<200;i++){
		if(a[i]!=0){
			cout<<"contest"<<endl;
			return ;
		}
	}
	cout<<"home";
}
int main()
{
	sol();
	return 0;
}
//A.cc
//generated automatically at Tue Feb 14 16:38:15 2017
//by xsthunder

