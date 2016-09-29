#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
typedef long long int ll;
using namespace std;
bool isSubsequence(string s,string t){
	auto tit=t.begin();
	auto sit =s.begin();
	while(tit!=t.end()){
		if(*tit==*sit){
			tit++;
			sit++;
		}
		else {
			tit++;
		}
		if(sit==s.end())return 1;
	}
	return 0;
}
int main()
{
//#ifdef DEBUG
//	freopen("in", "r", stdin);
////	freopen("out", "w", stdout);
//#endif
	string s,t;
	cin>>s>>t;
	cout<<(isSubsequence(s,t));
	cout<<endl;

	//insert code above
	return 0;
}
//lcW3_1.cc
//generated automatically at Sun Sep  4 20:03:47 2016
//by xsthunder

