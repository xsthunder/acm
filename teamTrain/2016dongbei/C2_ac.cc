#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;
#define iF if(Te)
#define MS(m) memset(m,0,sizeof(m))
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif

typedef unsigned U;
void inp();
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		ll a,b;
		cin>>a>>b;
		cout<<"Case #"<<i<<":\n";
		if(a==b){
			cout<<1<<endl;
			cout<<a<<' '<<b<<endl;
		}
		else {
			cout<<2<<endl;
			cout<<a<<' '<<b<<endl;
			cout<<b<<' '<<a<<endl;
		}
	}
	return 0;
}
void inp(){

}
//C2.cc by xsthunder at Tue May 16 19:18:04 2017

//AC at Tue May 16 20:39:28 2017
 
