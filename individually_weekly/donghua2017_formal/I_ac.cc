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
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void inp(){
	int n;
	if(!(cin>>n))exit(0);
	int ans=0;
	for(int i=1;i<n;i++){
		if(gcd(i,n)==1)ans++;
	}
	cout<<ans<<endl;
}
//I.cc by xsthunder at Sat Jun  3 13:10:27 2017

//AC at Sat Jun  3 13:40:32 2017
 
