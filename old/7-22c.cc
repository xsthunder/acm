#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<cctype>
#include<cstring>
#include<utility>
#include<deque>
using namespace std;
const int inf=0x7fffffff;
string src;
string trgt;
bool checklen(const string &a)
{
	return a.length()==trgt.length();
	
}
bool check(const string &a){
	return !a.compare(trgt.substr(0,a.length()));
}
void defs(string stem,deque<char> dc,stack<char> sc,vector<char> vc,char ch)
{
	if(ch=='i'){
		vc.push_back(ch);
		if(dc.empty())return;
		sc.push(dc.front());
		dc.pop_front();
		defs(stem,dc,sc,vc,'i');
		defs(stem,dc,sc,vc,'o');
	}
	if(ch=='o'){
		vc.push_back(ch);
		if(sc.empty())return;
		stem+=sc.top();
		sc.pop();
		if(check(stem)){
			if(checklen(stem)){
	//			cout<<stem.compare(trgt.substr(0,stem.length()))<<' '<<trgt<<' '<<trgt.substr(0,stem.length())<<endl;
				printf("%c",vc[0]);
				for(int i=1;i<vc.size();i++)
					printf(" %c",vc[i]);
				printf("\n");
			}
			else
			{
			defs(stem,dc,sc,vc,'i');
			defs(stem,dc,sc,vc,'o');
			}
		}
		else return;


	}
}
int main()
{

#ifdef DEBUG
//	freopen("in", "r", stdin);
//	freopen("out", "w", stdout);
#endif
	while(cin>>src>>trgt)
	{
		deque<char>dc;
		for(char i:src)
		{
			dc.push_back(i);//将source保存到dc中
		}
		string stem="";
		stack<char>sc;
		vector<char> vc;
		printf("[\n");
		defs(stem,dc,sc,vc,'i');//参数为当前字符串，当前栈，当前保存了的操作，要进行的操作
		printf("]\n");
	}
	
	//insert code
	return 0;
}
