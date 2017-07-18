#include<iostream>
#include<cstdio>
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
		while(1)
		inp();
	}
	catch(... ){
#ifdef XS
		printf("%s","exception");
#endif
	}//for compatibility with cygwin c++ runtime
	return 0;
}
int Tcnt = 1;
int len ;
const int N = 1e6+1000;
char s[N];
int nxt[N];
void getNxt(char *a,int len){
	nxt[0]=nxt[1]=0;
	int j = 0;
	for(int i = 1;i < len ;i++){
		while(j>0&&a[i]!=a[j])j=nxt[j];
		if(a[i]==a[j])j++;
		nxt[i+1]=j;
	}
}
void inp(){
	scanf("%d",&len);
	if(!len)exit(0);
	printf("Test case #%d\n", Tcnt++);
	scanf("%s",s);
	getNxt(s,len);
#ifdef XS
	pA(nxt,len+1);
#endif
	for(int i = 2;i<=len;i++){
		if(!nxt[i])continue;
		int cnt = i - nxt[i];
		if(i%cnt==0)printf("%d %d\n", i,i/cnt);
	}
	printf("\n");
}
//poj1961.cc by xsthunder at Sat Jul 15 15:51:30 2017

//AC at Sat Jul 15 16:00:18 2017
 
