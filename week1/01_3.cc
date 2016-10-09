const bool test=1;
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
const int inf=0x7fffffff;
#define IF if(test)
#define FI if(!test)
#define gts(s) fgets((s),sizeof(s),stdin)
typedef long long int ll;
using namespace std;
typedef pair<int,int> point;
template <typename T>
void pA(T *begin,int n){ for(int i=0;i<n;i++){ printf("%d " ,*(begin+i)); } printf("\n"); }
set<string> ss;
void adda(string &s){
	size_t p=s.find_last_of('/');
	s.insert(p+1,1,'~');
}
void addl(string &s){
	s+="/";
}
void priw(string x,int cnt){
	while(cnt--){
		printf("%4c",' ');
	}
	cout<<x<<endl;
}
void rma(string &x){
	size_t p=x.find_last_of('/');
	if(x[p+1]=='~')x.erase(p+1,1);
}
void pri(string a,string b){
//		cout<<a<<' '<<b<<endl;
	int cnta=0;
	int i=0;
	int cnt=0;
//	int ls=0;
	if(b=="0"){
	}
	else {
		rma(b);
		addl(b);
//		cout<<a<<' '<<b<<endl;
		for(int i=0;i<a.size()&&i<b.size()&&a[i]==b[i];i++){
			if(a[i]=='/'){
				cnta=i;
				cnta++;
				cnt++;
			}
		}
	}
	rma(a);
	addl(a);
	for(i=cnta;i<a.size();i++){
		if(a[i]=='/'){
//			printf("*****cnta:%d i-cnta:%d\n",cnta,i-cnta);
//			cout<<a<<endl;
			priw(a.substr(cnta,i-cnta),cnt++);
			cnta=i+1;
		}
	}
}
void sol(){
	int t=0;
string s;
	while(getline(cin,s)){
		if(s.size()==1&&s[0]=='0'){
			printf("Case %d:\n",++t);
//			IF for(string x:ss)cout<<x<<endl;
			string _s;
			bool flag=1;
			for(string x:ss){
//				cout<<"flag"<<flag<<endl;
				if(flag){
					pri(x,string("0"));
					_s=x;
					flag=0;
				}
				else {
					pri(x,_s);
					_s=x;
				}
			}
			ss.clear();
//			IF return;
			continue;
		}
//		cout<<"fore"<<s<<endl;
		adda(s);
		ss.insert(s);
	}
}
int main()
{
	sol();
	string s;
//	while(getline(cin,s)){adda(s);rma(s);cout<<s<<endl;}
	return 0;
}
//01_3.cc
//generated automatically at Sun Oct  9 19:58:35 2016
//by xsthunder

