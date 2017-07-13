#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<set>
#ifdef XS
	const int Te=1;
#include<De>
#else 
	const int Te=0;
#endif
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
	try{
		//n;scanf("%d",&n);for(int i=1;i<=n;i++)
		while(1)inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 1e5+ 1e4;
int p[N];
int find(int a){
	if(p[a]<0)return a;
	return p[a]=find(p[a]);
}
void uni(int fa,int fb){
	if(p[fa]>p[fb])swap(fa,fb);
	p[fa]+=p[fb];
	p[fb]=fa;
}
char ans[][10]={
	"No\n",
	"Yes\n"
};
set<int> s;
void inp(){
	int a,b;
	int flag=1;
	s.clear();
	memset(p,-1,sizeof(p));
	while(scanf("%d%d",&a,&b)!=-1&&a&&b){
		if(a==-1&&b==-1)exit(0);
		if(!flag)continue;
		s.insert(a);
		s.insert(b);
		int fa = find(a);
		int fb =  find(b);
	//	printf("%d , %d\n",fa,fb);
		if(fa==fb){ flag=0; }
		uni(fa,fb);
	}
	int cntfa = 0;
	if(flag)
		for(set<int>::iterator it = s.begin();it!=s.end();it++){
			if(p[*it]<0)cntfa++;
		}
	if(cntfa>1)flag=0;
	//pA(p,10);
	printf("%s", ans[flag]);
}
//hdu1272.cc by xsthunder at Wed Jul 12 20:02:13 2017

//AC at Wed Jul 12 20:34:03 2017
 
