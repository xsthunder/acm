const bool TEST=1;
#include<iostream>
#include<cctype>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<cctype>
#include<cstring>
#include<utility>
#include<cmath>
#include<stack>
#include<sstream>
const int inf=0x7fffffff;
#define IF if(TEST)
#define FI if(!TEST)
#define gts(s) fgets((s),sizeof(s),stdin)
#define ALL(s) (s).begin(),(s).end()
#define MK(a,b) make_pair((a),(b))
typedef long long int LL;
typedef unsigned int U;
typedef unsigned long long ULL;
using namespace std;
typedef pair<int,int> Point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ cout<<*(begin++); } printf("\n"); }
int cal(int x , char m,char y ) {
	switch(m){
		case '-':
			return x-y;
		case '+':
			return x+y;
		case '/':
			return x/y;
		case '*':
			return x*y;
		default:
			exit(2);
	}
}
int cmp(char cur  , char top ) {
	if(top=='#'){
		if(cur=='#')return 0 ;
		else return 1;
	}
	else if(top=='('){
		if(cur==')')return 0;
		else return 1;
	}
	else if(top==')'){
		return -1;
	}
	else if(top=='+'||top=='-'){
		switch(cur){
			case '#' :return -1;
			case ')':return -1;
			case '(':return 1;
			case '+':
			case'-':return -1;
			case'*':
			case'/':return 1;
		}
	}
	else if(top=='*'||top=='/'){
		switch(cur){
			case '#' :return -1;
			case ')':return -1;
			case '(':return 1;
			case '+':
			case'-':return -1;
			case'*':
			case'/':return -1;
		}
	}
	else exit(3);
}
void sol(){
	string s; 
	stack <char >ope;
	stack <int > num;
	cin >>s;
	s.push_back('#');
	ope.push('#');
	stringstream ss;
	int n = 100;
	while(n--){
		ss.clear();
		ss.seekg(0);
		IF cout<<s<<endl;
		ss.str(s);
//		IF cout<<s<<endl;
		if(isdigit(s[0])){
			int x ; 
			ss>>x;
			num.push(x);
			IF cout<<"push int : "<<x<<endl;
		}
		else {
			char x='I' ;  
			ss>>x;
			IF{
				cout<<x<<endl;
			}
				cout<<"cur: "<<x<<" top: "<<ope.top()<<endl;
			switch(cmp(x,ope.top())){
				case 1:
					ope.push(x);
					IF cout<<"pushing "<<x<<endl;
					break;
				case 0:
					IF cout<<"poping "<<x<<" "<<ope.top()<<endl;
					ope.pop();
					break;
				case -1:
					int x2,y;
					do{
					x2=num.top();
					num.pop();
					y=num.top();
					num.pop();
					char m = ope.top();
					ope.pop();
					int ans=cal(x2,m,y);
					IF printf("cal %d,%c,%d %d\n",x2,m,y,ans);
					num.push(ans);
					}while(cmp(x,ope.top())==-1);
					ope.push(x);
					break;
			}
		}
		ss>>s;
	}
	if(num.size()){
		int ans = 0 ; 
		ans=num.top();
		cout<<ans<<endl;
	}

}
int main()
{
	sol();
	return 0;
}
//419.cc
//generated automatically at Thu Jan 26 20:19:20 2017
//by xsthunder

