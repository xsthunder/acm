const bool test=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
const int N=40;
const int M=200;
char s[N][M];
int cnt;
void init(){
	cnt=0;
}
vector<string > v;

void Inp(){
	string tmp;
	do{
		gts(s[cnt++]);getchar();
		if(s[cnt-1][0]=='0')break;
	}while(1);
	IF for(int i=0;i<cnt;i++)cout<<s[i]<<endl;
	
	FI for(int i=0;i<cnt;i++){
		char *p;
		v.clear();
		p=strtok(s[i],"\\");
		while(p!=NULL){
			v.push_back(string(p));
		}
		for(string x:v)cout<<x<<',';
		//cout<<endl;
	}
}
void sol(){
	while(!cin.eof()){
		init();
		Inp();
	}
}
int main()
{
	sol();
	return 0;
}
//01.cc
//generated automatically at Fri Oct  7 21:26:54 2016
//by xsthunder

