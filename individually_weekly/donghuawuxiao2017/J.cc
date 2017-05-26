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
typedef pair<int,int > P;
void inp();
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while(1)inp();
	return 0;
}
typedef long long ll;

void inp(){
	ll x;
	if(!(cin>>x))exit(0);
	ll mask=1;
	int cnt =0;
	for(int i=0;i<=33;i++){
		cnt+=((mask<<i)&x)?1:0;
	}
	cout<<cnt<<endl;
}
//J.cc by xsthunder at Fri May 26 10:47:46 2017

