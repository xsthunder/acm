const bool test=1;
#include<iostream>
#include<list>
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
void sol(){
	int n;
	string s ;
	list < char > l;
	cin >> n>>s;
	if(n%2)l.push_back(s[0]);
	for(unsigned int i=n%2;i<s.length();i++){
		l.push_front(s[i++]);
		l.push_back(s[i]);
	}
	for(char x:l){
		cout<<x;
	}
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//B2.cc
//generated automatically at Sun Dec 18 19:14:13 2016
//by xsthunder

