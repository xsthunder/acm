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
const int N = 3e5;
int a[N];
void inp(){
	int n;
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2){//odd
		for(int i =n;i>=1;i-=2){
			cout<<a[i]<<' ';
		}
		for(int i=2;i<=n;i+=2){
			cout<<a[i]<<' ';
		}
	}
	else {
		//even
		for(int i=n;i>=2;i-=2){
			cout<<a[i]<<' ';
		}
		for(int i=1;i<=n;i+=2){
			cout<<a[i]<<' ';
		}
	}
}
//C.cc by xsthunder at Sat Jul  1 23:26:43 2017

//AC at Sun Jul  2 00:37:22 2017
 
