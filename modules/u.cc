#ifdef XS
	#include</home/xs/acm/modules/mylib/De>
	#include<cassert>
	#define NDEBUG
	const int Te=1;
#else 
	const int Te=0;
#endif
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<utility>
using namespace std;
#define IF if(Te)
#define MS(m) memset(m,0,sizeof(m))

typedef unsigned U;
typedef pair<int,int > P;
typedef long long ll;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	try{
		inp();
	}
	catch(... ){
		IF cout<<"exception";
	}//for compatibility with cygwin c++ runtime
	return 0;
}
void inp(){

}
