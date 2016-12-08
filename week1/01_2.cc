const bool test=0;
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
char s[200];
set<string> ss;
vector<string> curv;
vector<string> v;
void Pri(string &x,int s){
	for(int i=0;i<s;i++){
		printf("    ");
	}
	cout<<x<<endl;;
}
void sol(){
	while(fgets((s),sizeof(s),stdin)!=NULL){
		//getchar();
		IF cout<<s;
		if(s[0]=='0'){
			int cnt=0;
			for(string x:ss){
				memcpy(s,x.c_str(),sizeof(x.c_str()));
				char *p;
				p=strtok(s,"\\");
				while(p!=NULL){
					curv.push_back(string(p));
					p=strtok(s,"\\");
				}
				if(cnt==0){
					v=vector<string> (curv);
					int cntspc=0;
					for(string x:curv){
						Pri(x,cntspc++);
					}
					cnt++;
					curv.clear();
				}
				else {
					int i;
					bool flag=1;
					int cntspc=0;
					for(i=0;i<curv.size();i++){
						if(i<v.size()&&curv[i]==v[i]&&flag){
							cntspc++;
							continue;
						}
						else {
							flag=0;
							Pri(v[i],cntspc);
							cntspc++;
						}
					}
					v=vector<string >(curv);
					curv.clear();
					cnt++;
				}
			}
			cnt=0;
		}
		else ss.insert(string(s));
	}
}
int main()
{
    freopen("in","r",stdin);
	sol();
	return 0;
}
//01_2.cc
//generated automatically at Sat Oct  8 18:15:49 2016
//by xsthunder

