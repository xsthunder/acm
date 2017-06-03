#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
char s[100];
int len;
bool in(int s){
	return s<len&&s>=0;
}
int cal(int st){
	int cnt =1;
	int si=st-1,ei=st+1;
	while(in(si)&&in(ei)&&s[ei]==s[si]){
		//cout<<1;
		cnt+=2;
		si--;
		ei++;
	}
	return cnt;
}
int cal(int si,int ei){
	if(s[si]!=s[ei])return 0;
	int cnt =2;
	si=si-1,ei=ei+1;
	while(in(si)&&in(ei)&&s[ei]==s[si]){
		//cout<<2;
		cnt+=2;
		si--;
		ei++;
	}
	return cnt;
}
void inp(){
	if(!(cin>>s))exit(0);
	int m=1;
	len = strlen(s);
	for(int i =0;i<len-1;i++){
		int t = cal(i,i+1);
		m=max(t,m);
	}
	for(int i =0;i<len;i++){
		int t = cal(i);
		m=max(t,m);
	}
	cout<<m<<endl;
}
//E.cc by xsthunder at Sat Jun  3 12:57:34 2017

//AC at Sat Jun  3 13:10:20 2017
 
