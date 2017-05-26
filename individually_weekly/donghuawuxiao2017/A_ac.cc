#include<iostream>
#include<stack>
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
char s[200];
stack<int > sk;
void inp(){
	if(!(cin>>s))exit(0);
	int len=strlen(s);
	while(!sk.empty())sk.pop();
	int flag=1;
	int m = 0; 
	for(int i =0;i<len;i++){
		char cur = s[i];
		if(cur=='('){
			sk.push('(');
			if(m<sk.size())m=sk.size();
		}
		else {
			if(sk.empty()){
				flag=0;
				break;
			}
			else sk.pop();
		}
	}
	if(!sk.empty())flag=0;
	if(flag){
		cout<<"YES "<<m;
	}
	else cout<<"NO";
	cout<<endl;
}
//A.cc by xsthunder at Fri May 26 09:38:33 2017

//AC at Fri May 26 09:55:23 2017
 
