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
const int N=1e5+30;
int A[N];
char s[N];
int main()
{

#ifdef DEBUG
	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	int T;
	SC(T);
	rep(t,1,T){
		MS(A);
		scanf("%s", s);
		int l=strlen(s);
		int len=0;
		char type=s[0];
		A[len]++;
		rep(i,1,l-1){
			//cout<<s[i]<<' ' <<type<<' '<<len<<endl;
			if(s[i]==type){
				A[len]++;
//printf("%d %d\n",i,A[len]);
			}
			else {
				len++;
				A[len]++;
				type=s[i];
			}
		}
//		rep(i,0,5){
//			printf("%d %d\n",i,A[i]);
//		}
///		break;
	}

	
	//insert code
	return 0;
}
//8-4b.cc

