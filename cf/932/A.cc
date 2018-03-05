#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
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
const int N = 1e3 + 100;
char s[N];
void inp(){
	scanf("%s", s);
	int len = strlen(s);
	for(int i = 0;i<len;i++){
		putchar(s[i]);
	}
	for(int i = len-1;i>=0;i--){
		putchar(s[i]);
	}
	putchar('\n');
}
//A.cc by xsthunder at Thu Feb 15 22:42:13 2018

