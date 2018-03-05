#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<list>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U;typedef long long ll;typedef pair<int,int > P;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int ttt;scanf("%d",&ttt);for(int i=1;i<=ttt;i++)
	inp();
	return 0;
}
char s[500];
int isvow[500];
int nxt[500];
int vow[] = {
	'a','e','i','o','u','y'
};
list<char> l;
void inp(){
	scanf("%*d%s",s);
	int V = sizeof(vow)/sizeof(int);
	for(int i = 0;i<V;i++){
		isvow[ vow[i] ] = 1;
	}
	int len = strlen(s);
	for(int i = 0;i<len;i++){
		int j = i - 1;
		if( j >= 0){
			if( isvow[ s[i] ] && isvow[ s[j] ])continue;
		}
		putchar( s[i] );
	}
}
//A.cc by xsthunder at Fri Feb 16 23:07:34 2018

