const bool TEST=0;
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
int n ;
string b;
bool ope(bool an_1,bool bn_1,bool an_2){
	return (an_1)?((!bn_1)^an_2):(bn_1^an_2);
}
void pri(string a ){
	for(char &x:a){
		x=x?'S':'W';
	}
	cout<<a;
}
bool build(int x){
	string a;
	a.push_back((x&2)>>1);
	a.push_back(x&1);
	for(int i = 2;i<n;i++){
		bool tmp=ope(a[i-1],b[i-1],a[i-2]);
		a.push_back(tmp);
		IF printf("i:%d,ope %d %d %d : %d\n",i,a[i-1],b[i-1],a[i-2],tmp);
	}
	if(a[1]==ope(a[0],b[0],a[n-1])&&a[0]==ope(a[n-1],b[n-1],a[n-2])){
		pri(a);
		return 1;
	}
	else return 0;
}
void sol(){
	cin>>n>>b;
	for(char &x:b){
		x=x=='o'?1:0;
	}

	IF {build(3);
	return ;
	}
	for(int i = 0 ;i< 4;i++){
		if(build(i)){
			exit(0);
		}
	}
	cout<<-1<<endl;
}
int main()
{
	sol();
	return 0;
}
//D.cc
//generated automatically at Sat Feb 18 21:17:19 2017
//by xsthunder

