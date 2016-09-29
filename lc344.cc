#include<iostream>
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
using namespace std;
#define MS(x) memset(x, 0 ,sizeof(x)) 
#define SC(x) scanf("%d", & (x) )
#define rep(i,x,y) for(register int i=(x);i<=(y);++i)
#define per(i,x,y) for(register int i=(x);i>=(y);--i)
const int inf=0x7fffffff;
typedef long long int lld;
typedef long long unsigned llu;

string solve(string s)
{
	if(s.length()==0)return s;
	int b=0;
	int e=s.length()-1;
	for(;;){
		if(b>=e)return s;
		else {
			swap(s[b],s[e]);
			b++;e--;
		}
	}
}
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	string s;
	s="hello";
	cout<<solve(s);

	
	//insert code
	return 0;
}
//lc344.cc

