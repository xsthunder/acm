#include<iostream>
#include<string>
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
	int t;
	cin>>t;
	while(t--)inp();
	return 0;
}
int get(char x){
	switch(x){
		case 'H':return 1;
		case 'C':return 12;
		case 'O':return 16;
	}
	return -100000;
}
void inp(){
	string s;
	cin>>s;
	int ans=0;
	for(U i =0;i< s.size();i++){
		ans+=get(s[i]);
	}
	cout<<ans<<endl;
}
//B.cc by xsthunder at Tue May  9 18:23:44 2017

