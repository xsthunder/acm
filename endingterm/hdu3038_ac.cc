#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<algorithm>
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
		while(1)inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int N = 2e5 + 100;
int p[N];
int w[N];
int find(int x){
	if(p[x]<0)return  x;
	int ans = find(p[x]);
	w[x] += w[p[x]];
	p[x] = ans;
	return  ans;
}
void inp(){
	int n,m;
	if(!~scanf("%d%d", &n,&m))exit(0);;
	MS(w);
	memset(p,-1,sizeof(p));
	int cnt = 0;
	while(m--){
		int a,b,c;
		scanf("%d%d%d", &a,&b,&c);
		a--;
		int fa = find(a);
		int fb = find(b);
		if(fa == fb){
			if(w[b] - w[a] != c)cnt++;
		}
		else {
			if(fa>fb){
				swap(fa,fb);
				c=-c;
				swap(a,b);
			}
			p[fa]+=p[fb];
			p[fb]= fa;
			w[fb]= -w[b] + w[a] + (c);
		}
#ifdef XS
		pA(p,n+1);
		pA(w,n+1);
#endif

	}
	printf("%d\n",cnt);
}
//hdu3038.cc by xsthunder at Thu Jul 13 19:23:34 2017

//AC at Thu Jul 13 20:27:34 2017
 
