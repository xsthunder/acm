#include<cstdio>
#include<iostream>
#include<set>

#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	#include<De>
#endif
using namespace std;
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
#ifdef XS
	//freopen(".in","r",stdin);
#endif
	try{
		//while(1)
		//int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
void inp(){
	set<int> s1;
	set<int> s2;
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i<m;i++){
		int a,b;scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		if(a == 1)s1.insert(b);
		if(b == n)s2.insert(a);
	}
	char ans[2][20]={
		"IMPOSSIBLE",
		"POSSIBLE"
	};
	for(auto x:s1){
		if(s2.count(x)){
			cout<<ans[1];
			return; 
		}
	}
	cout<<ans[0];
}
//A.cc by xsthunder at Sat Jul 29 20:02:43 2017

//AC at Sat Jul 29 20:23:42 2017
 
