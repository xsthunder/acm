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
    int t=0;
	while(fgets((s),sizeof(s),stdin)!=NULL){
		//getchar();
		s[strlen(s)-1]='\0';
		//IF cout<<s<<endl;
		if(s[0]=='0'){
		    cout<<ss.size()<<endl;
            printf("Case %d:\n", ++t);
			int cnt=0;
			for(string x:ss){
				memcpy(s,x.c_str(),sizeof(x.c_str()));
				char *p;
				p=strtok(s,"/");
				while(p!=NULL){
					curv.push_back(string(p));
					p=strtok(NULL,"/");
				}
				if(cnt==0){
					v=vector<string> (curv);
					int cntspc=0;
					for(string x:curv){
						Pri(x,cntspc++);
					}
					cnt++;
				}
				else {
					int i;
					bool flag=1;
					int cntspc=0;
                    IF {
                        for(string x :v)cout<<x<<' ';
                        cout<<'|';
                        for(string x:curv) cout<<x<<' ';
                        cout<<endl;
                    }
					for(i=0;i<curv.size();i++){
						if(i<v.size()&&curv[i]==v[i]&&flag){
						    cout<<"skip:"<<v[i]<<endl;
							cntspc++;
							continue;
						}
						else {
							flag=0;
							Pri(curv[i],cntspc);
							cntspc++;
						}
					}
					v=vector<string >(curv);
					v.clear();
					cnt++;
				}
			}
			cnt=0;
			ss.clear();
			v.clear();
			curv.clear();
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

