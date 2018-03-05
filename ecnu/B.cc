#include<cstdio>
#include<iostream>
#include<vector>
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
const int N = 1e5 + 100;
char s[N],ans[N];
int mp[30];
int done = 0;
vector<P > v;
int len = 0;
void dfs(int p){
	if(p == len)done = 1;
	if(done)return;
	for(int i =0 ;i<26;i++){
		if( i == s[p] ) continue;
		if(mp[i]){
			mp[i] --;
			ans[p] = i;
			dfs(p+1);
			if(done)return;
			mp[i] ++;
		}
	}
}
void inp(){
	scanf("%s",s);
	len = strlen(s);
	for(int i = 0;i<len;i++){
		s[i] -= 'a';
		mp[ (int)s[i] ] ++;
	}
	dfs(0);
	if(done){
		for(int i = 0;i<len;i++)ans[i]+='a';
		puts(ans);
	}
	else puts("impossible");
	return;
}
//B.cc by xsthunder at Fri Dec  8 18:42:23 2017

