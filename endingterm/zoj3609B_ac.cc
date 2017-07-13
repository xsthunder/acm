#include<iostream>
#include<cstdlib>
#include<cstring>
#include<utility>
#ifdef XS
	const int Te=1;
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
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	int gcd = exgcd(b,a%b,x,y);
	int tmp = x;
	x = y;
	y = tmp - (a/b)*y;
	return gcd;
}
int main(){
	try{
		int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		inp();
	}
	catch(... ){
		IF printf("%s","exception");
	}//for compatibility with cygwin c++ runtime
	return 0;
}
const char * imp ="Not Exist";
void inp(){
	int a,m,x,y;
	scanf("%d%d",&a,&m);
	int gcd = exgcd(a,m,x,y);
	if(gcd!=1){
		printf("%s\n",imp);
		return;
	}
	x%=m;
	if(x<=0)x+=m;
	printf("%d\n", x);
}
//zoj3609B.cc by xsthunder at Fri Jul  7 18:30:02 2017

//AC at Fri Jul  7 18:42:43 2017
 
