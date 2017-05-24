#include<cstdio>
#include<stack>
#include<string>
#include<sstream>
#include<iostream>
#define IF if(test)
const int test = 1;
using namespace std;





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

ss.str(s);

while(!ss.eof()){

if(isdigit(ss.str()[ss.tellg()])){

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

IF cout<<"cur: "<<x<<" top: "<<ope.top()<<endl;

re:

if(ope.empty())break;

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

x2=num.top();

num.pop();

y=num.top();

num.pop();

char m = ope.top();

ope.pop();

int ans=cal(y,m,x2);

IF printf("cal %d,%c,%d %d\n",y,m,x2,ans);

num.push(ans);

goto re;

break;

}

}

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

