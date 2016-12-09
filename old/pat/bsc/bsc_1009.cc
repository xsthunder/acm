const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<stack>
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
	stack<string> ss;
	string s;
	while(cin>>s){
		ss.push(s);
	}
	bool flag=1;
	while(!ss.empty()){
		s=ss.top();
		if(flag==0)cout<<' ';
		cout<<s;
		flag=0;
		ss.pop();
	}
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//bsc_1009.cc
//generated automatically at Tue Nov  1 21:38:40 2016
//by xsthunder

//AC at Tue Nov  1 21:42:36 2016
 
