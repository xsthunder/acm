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
char stmp[200];
set<string > s;
vector<string> v,_v;
void sol(){
	string tmp;
	bool flag=1;
	while(getline(cin,tmp)){
		if(tmp[0]=='0'){
			for(string x:s){
				memcpy(stmp,x.c_str(),x.length());
				char *p=strtok(stmp,"\\");
				while(p!=NULL){
					v.push_back(string (p));
				}
				IF {
					for(string x:v)cout<<x<<',';
					cout<<endl;
				}
				if(flag){
					flag=0;
					_v=vector<string> (v);
				}
			}
		}
	}

}
int main()
{
	sol();
	return 0;
}
//01_1.cc
//generated automatically at Sat Oct  8 14:25:34 2016
//by xsthunder

