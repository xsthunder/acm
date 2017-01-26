const bool TEST=0;
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
void sol(){
	string s; 
	int n;
	cin>>n;
	cin >> s ;
	bool flag=1;
	bool single=1;
	ULL ans=0;
	while(s.size()>1){
		char x = s[0];
		U pos = s.find_last_of(x);
		if(pos<0){
			flag=0;
			break;
		}
		else if(0==pos){
			if(single){
				single=0;
				if(s.size()%2==0){
					flag=0;
					break;
				}
				else ans+=s.size()/2;
				s.erase(0,1);
			}
			else {
				flag=0;
				break;
			}
		}
		else {
			ans+=s.size()-pos-1;
			s.erase(pos,1);
			s.erase(0,1);
		}
		IF cout<<s<<endl;;
	}
	if(flag)cout<<ans;
	else cout<<"Impossible";
	cout<<endl;
}
int main()
{
	sol();
	return 0;
}
//59.cc
//generated automatically at Wed Jan 18 20:25:13 2017
//by xsthunder

