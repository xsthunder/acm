#include<cstdio>
#include<map>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define MS(m,z) memset(m,z,sizeof(m))
typedef unsigned U; typedef pair<int,int > P; typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
	inp();
	return 0;
}
map<char,char>mp;
const int N = 30;
char s1[N],s2[N];
char s[1111];
void inp(){
	scanf("%s%s",s1,s2);
	int l = strlen(s1);
	int i;
	for(i=0;i<l;i++){
		mp[s1[i]]=s2[i];
		mp[toupper(s1[i])] = toupper(s2[i]);
	}
	for(i='0';i<='9';i++)mp[(char)i]=(char)i;
	scanf("%s",s);
	l = strlen(s);
	for(i = 0;i<l;i++){
		putchar(mp[s[i]]);
	}
	puts("");
}
//cf831b.cc by xsthunder at Sun Aug  6 08:49:11 2017

//AC at Sun Aug  6 08:59:43 2017
 
