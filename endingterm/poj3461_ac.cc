#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<utility>
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
#ifdef XS
	freopen("poj3461.in","r",stdin);
#endif
	try{
		int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const int W  = 1e4 +100;
const int T  = 1e6 + 1000;
char w[W];
char t[T];
int nxt[W];
int wlen,tlen;
void getNxt(char *a, int len ){
	MS(nxt);
	nxt[0]=nxt[1]=0;
	int j = 0;
	for(int i = 1;i < len;i++){//从1开始，计算长度为2的nxt数组
		while(a[j]!=a[i]&&j>0)j=nxt[j];
		if(a[i]==a[j])j++;
		nxt[i+1]=j;
	}
}
int cnt;
void sea(){
	int j = 0;
	for(int i = 0;i<tlen;i++){
		while(t[i]!=w[j]&&j>0)j=nxt[j];
		if(t[i]==w[j])j++;
		if(j==wlen){
			cnt++;
			j=nxt[j];
		}
	}
}
void inp(){
	cnt=0;
	scanf("%s%s", w,t);
	wlen = strlen(w);
	getNxt(w,wlen);
	tlen = strlen(t);
	sea();
	printf("%d\n", cnt);
#ifdef XS
	pA(nxt,wlen+1);
#endif
}
//poj3461.cc by xsthunder at Sat Jul 15 09:32:03 2017

//AC at Sat Jul 15 10:27:41 2017
 
