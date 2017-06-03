#include<iostream>
#include<algorithm>
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
char s[300][10];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
void inp(){
	int cnt =0;
	if(!(cin>>cnt))exit(0);
	char os[] = "STEED";
	int len = strlen(os);
	sort(os,os+len);
	int tcnt=0;
	do{
		tcnt++;
		if(cnt==tcnt){
			cout<<os<<endl;
			return ;
		}
	}while(next_permutation(os,os+len));
}
//A.cc by xsthunder at Sat Jun  3 12:02:42 2017

//AC at Sat Jun  3 12:14:04 2017
 
