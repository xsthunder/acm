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
string s;
char ts[200];
void priw(string s,int i){
	//IF cout<<"modiing --"<<endl;
	for(int j=0;j<i;j++){
		printf("%4c",' ');
	}
	cout<<s<<endl;
	//IF cout<<"end modiing --"<<endl;

}
void modi(string &a){
	auto p=s.find_last_of('/');
	if(p==string::npos){
		p=0;
	}
	else {
		p++;
	}
	s.erase(s.begin()+p);
}
void pri(const string &a,const string &b){
	int cnta=0;
	int i=0;
	int cnt=0;
	for(i=0;i<a.size()&&i<b.size()&&a[i]==b[i];i++){
		if(a[i]=='/')cnt++;
	}
	if(i==0){
		cnta=0;
	}
	else {
		int j=0;
		for(j=i;j>=0;j--){
			if(s[j]=='/'){
				j++;
				break;
			}
			if(j==0)break;
		}
		cnta=j;
	}
//	IF {
		cout<<"-------"<<endl<<a<<endl<<b<<endl<<"######"<<endl;
		//cout<<"cnta"<<cnta<<endl;
//	}
	for(i=cnta;i<a.size();i++){
		if(a[i]=='/'){
			//cout<<"subing"<<i<<"len"<<i-cnta<<a<<endl;
		//	cout<<cnt<<endl;
			priw(a.substr(cnta,i-cnta),cnt++);
			cnta=i+1;
		}
	}
//	IF cout<<"last"<<endl;
	cout<<"###"<<s<<' '<<cnta<<i<<endl;
	priw(s.substr(cnta,cnta-i),cnt++);
}
void sol(){
	int t=0;
	while(getline(cin,s)){
		getchar();
		if(s[0]=='0'){
		IF for(string x:ss){cout<<x<<endl;return;}
			printf("Case %d:\n",++t);
			auto it=ss.begin();
			string _s;
			while(it!=ss.end()){
				s=*it;
				modi(s);
				if(it==ss.begin()){
//					int j=0;
//					while(j<s.size()){
//						int cnt=0;
//						int i;
//						for(i=j+1;;i++){
//							if(s[i]=='/'||s[i]=='\0')
//							{
//								if(s[i]=='\0'){j++;
//									j++;
//								}
//								priw(s.substr(j,i-j),cnt++);
//								j=i;
//								if(s[i]=='\0')break;
//							}
//						}
//						j=i;
					pri(s,string("a"));
					_s=s;
				}
				else {
					modi(s);
					pri(s,_s);
					_s=s;
				}
				it++;
			}
			ss.clear();
			continue;
		}
		//		IF cout<<ts;
			s.erase(s.end()-1);
		size_t p=s.find_last_of('/');
		if(p==string::npos){
			s.insert(0,1,'a');
		}
		else {
			s.insert(p+1,1,'a');
		}
		//cout<<'\''<<s<<'\''<<endl;
		ss.insert(s);
	}
	//IF cout<<ss.size()<<endl;
}
int main()
{
//	IF while(cin>>s){
//		modi(s);
//		cout<<s;
//	}
	sol();
	return 0;
}
//01_2.cc
//generated automatically at Sun Oct  9 16:03:52 2016
//by xsthunder

