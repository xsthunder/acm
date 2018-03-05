#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<string>
#include<unordered_map>
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
unordered_map<string ,string> mp;
const int N = 5e5;
char s[N],s2[N];
void inp(){
	scanf("START\n");
	while(scanf("%s", s)&&s[0]!='E'){
		scanf("%s\n",s2);
		mp[string(s2)] = string(s);
	}
	getchar();
	scanf("START\n");
	while(fgets(s,sizeof(s),stdin)&&s[0]!='E'){
		char *p = s;int len;
		while( *p != '\0'){
			len = 0;
			while( islower(p[len]) ){
				len++;
			}
			string ss(p , len);
			if(mp.count(ss))printf("%s",mp[ss].c_str());
			else printf("%s",ss.c_str());
			p = p + len;
			while( !islower(*p) && *p !='\0'){
				putchar(*(p++));
			}
		}
	}
}
//tmp.cc by xsthunder at Sun Dec 10 19:05:37 2017

