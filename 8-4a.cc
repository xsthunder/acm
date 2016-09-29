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
int turn(char x){
	return x-'a';
}
typedef struct point point ;
const int N=30;
int last[N];
int flag[N];
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	SC(T);
	rep(t,1,T){
		MS(last);MS(flag);
		string s;
		cin>>s;
		int best =inf;
		for(int i=0;i<s.length();i++){
			int tmp=turn(s[i]);
			if(flag[tmp]){best=min(best,-(last[tmp]-i));
				last[tmp]=i;
			}
			else {
				flag[tmp]=1;
				last[tmp]=i;
			}
		}
//	for(int i=0;i<5;i++)printf("%d %d %d\n", i,flag[i],last[i]);
		printf("Case #%d: %d\n" ,t,best==inf?-1:best);
	}

	
	//insert code
	return 0;
}
//8-4a.cc

//AC

