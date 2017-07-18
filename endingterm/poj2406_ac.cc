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
const int N = 1e6+1000;
char s[N];
int nxt[N];
void getNxt(char *a,int len){
	nxt[0]=nxt[1]=0;
	int j =0;
	for(int i = 1;i<len;i++){
		while(j>0&&a[i]!=a[j])j=nxt[j];
		if(a[i]==a[j])j++;
		nxt[i+1]=j;
	}
}
void inp(){
	if(!~scanf("%s",s))exit(0);
	if(s[0]=='.')exit(0);
	int len = strlen(s);
	if(len==1){
		printf("1\n");
		return;
	}
	getNxt(s,len);
	int cnt = 1;
	int flag = 0;
	for(int i = 1;i<=len;i++){
		if(cnt==nxt[i]){
			cnt++;
			flag=1;
		}
		else {
			cnt=1;
			flag=0;
		}
	}
	if(!flag){
		printf("1\n");
		return;
	}
	cnt--;
	int de = len - cnt;
	while(1){
		if(de>cnt){
			printf("1\n");
			return;
		}
		if(len%de==0&&cnt%de==0){
			printf("%d\n",len/de);
			return;
		}
		de++;
	}
//	if(!(len%de)){
//		printf("%d\n",len/cnt);
//		return;
//	}
//	if(len%2&&de%2==0){
//		printf("1\n");
//		return;
//	}
#ifdef XS
	pA(nxt,len+1);
	printf("de:%d\n",de);
	return ;
#endif
	{
		//while(len%de)de++;
		printf("%d\n",len/(de));
	}
}
//poj2406.cc by xsthunder at Sat Jul 15 10:42:05 2017

//AC at Sat Jul 15 15:19:00 2017
 
