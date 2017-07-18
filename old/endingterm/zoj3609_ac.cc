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
const char * imp = "Not Exist";
void inp(){
	int a,m;
	scanf("%d%d", &a,&m);
	if(m==1){
		printf("1\n");
		return ;
	}
	for(int i =1;i<m;i++){
		if(i*a%m==1){
			printf("%d\n", i);
			return;
		}
	}
	printf("%s\n",imp);
	
}
//zoj3609.cc by xsthunder at Fri Jul  7 16:38:46 2017

//AC at Fri Jul  7 18:13:03 2017
 
