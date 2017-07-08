#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<utility>
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
void p(int a[]){
	printf("%d s:%d\n", a,sizeof(a));
}
void inp(){
	int a[5]={0};
	printf("%d s:%d\n", a,sizeof(a));
	p(a);
}
//tmp.cc by xsthunder at Sun Jun 18 10:58:25 2017

