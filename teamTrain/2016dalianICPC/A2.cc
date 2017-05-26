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
void inp(){
	int n,m,x,y;
	if(!(cin>>n>>m>>x>>y))exit(0);
	while(m--)cin>>n>>n;
	for(int i=0;i<x;i++){
		cin>>n;
	}
	for(int i=0;i<y;i++){
		cin>>n;
	}
	if(x==0&&y==0)cout<<"NO\n";
	else cout<<"YES\n";
}
//A2.cc by xsthunder at Thu May 25 11:42:03 2017

