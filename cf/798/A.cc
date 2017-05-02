#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
#define iF if(Te)
#ifdef XS
	#include<De>
	const int Te=1;
#else 
	const int Te=0;
#endif
void inp();
char ans[2][20]={
	"YES\n",
	"NO\n"
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	inp();
	return 0;
}
void inp(){
	string s;
	cin>>s;
	int a=0;
	int b;
	b=s.length()-1;
	int flag=1;
	while(a<b){
		if(s[a]!=s[b]){
			if(flag){
				flag=0;
			}
			else {
				cout<<ans[1];
				exit(0);
			}
		}
		{
			a++,b--;
		}
	}
	if(flag&&s.length()%2==1){
		cout<<ans[0];
		exit(0);
	}
	if(flag)cout<<ans[1];
	else cout<<ans[0];
}
//A.cc
//generated automatically at Tue May  2 20:45:56 2017
//by xsthunder

