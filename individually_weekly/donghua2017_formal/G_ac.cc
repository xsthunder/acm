#include<iostream>
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
void inp(){
	int n,m;
	if(!(cin>>n>>m))exit(0);
	int a=min(n,m);
	int b=max(n,m);
	cout<<(b-a==1?"NO":"YES");
	cout<<endl;
}
//G.cc by xsthunder at Sat Jun  3 13:40:39 2017

//AC at Sat Jun  3 13:45:51 2017
 
